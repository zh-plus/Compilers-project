//
// Created by 10578 on 11/4/2019.
//

#include "semantics.hpp"
#include "type.hpp"
#include "visitor.hpp"
#include "symbol.hpp"
#include "type_switch.hpp"


namespace SPL {

    using namespace std;

    /* Local Resolver */
    void SPL::Local_Resolver::resolve(AST *ast) {
        auto *global_scope = new Global_Symbol_Table();
        scope_stack.push_back(global_scope);

        visit(ast->program);

        ast->global_scope = global_scope;
    }

    void Local_Resolver::push_scope() {
        auto *local_scope = new Local_Symbol_Table(current_scope());
        scope_stack.push_back(local_scope);
    }

    Local_Symbol_Table *Local_Resolver::pop_scope() {
        auto scope = current_scope();
        scope_stack.pop_back();
        return (Local_Symbol_Table *) scope;
    }

    std::vector<Symbol_Table *> Local_Resolver::get_scope_stack() {
        return scope_stack;
    }

    void Local_Resolver::insert(Symbol_Entry *entry) {
        if (entry == nullptr) {
            cout << "Trying to insert nullptr!" << endl;
            return;
        }

        if (string name = entry->name; current_scope()->contains(name)) {
            int defined_line = current_scope()->lookup(name)->line_no;
            // Have been defined
            type_case(entry,
                      [&](Variable_Symbol *symbol) {
                          add_error(new Semantic_Error3(entry->line_no, defined_line, name));
                      },
                      [&](Struct_Def_Symbol *symbol) {
                          add_error(new Semantic_Error15(entry->line_no, defined_line, name));
                      },
                      [&](Function_Symbol *symbol) {
                          add_error(new Semantic_Error4(entry->line_no, defined_line, name));
                      });

        } else {
            current_scope()->insert(entry);
        }
    }

    void Local_Resolver::visit(CompSt_Node *node) {
        push_scope();
        Visitor::visit(node);
        node->local_scope = pop_scope();
    }

    void Local_Resolver::visit(CompSt_Node *node, Local_Symbol_Table *local_scope) {
        push_scope(local_scope);
        Visitor::visit(node);
        node->local_scope = pop_scope();
    }


    void Local_Resolver::visit(Leaf_Node *node) {
        Visitor::visit(node);
    }

    void Local_Resolver::visit(ExtDef_Node *node) {
        Type *specifier_type = get_type(node->specifier);
        if (node->ext_dec_list) {
            auto *t_ext_dec_list = node->ext_dec_list;
            while (t_ext_dec_list) {
                auto var_symbol = get_var_symbol(specifier_type, t_ext_dec_list->var_dec);
                insert(var_symbol);

                t_ext_dec_list = t_ext_dec_list->ext_dec_list;
            }
        } else if (node->fun_dec) {
            auto *func_symbol = get_fun_symbol(specifier_type, node->fun_dec);
            insert(func_symbol);

            // Put parameter into scope and put them into stack
            push_scope();
            auto var_list = node->fun_dec->var_list;
            while (var_list) {
                ParamDec_Node *param_dec = var_list->param_dec;
                auto var_symbol = get_var_symbol(get_type(param_dec->specifier), param_dec->var_dec);
                insert(var_symbol);

                var_list = var_list->var_list;
            }
            visit(node->comp_st, pop_scope());

        } else if (auto p_struct_specifier = node->specifier->struct_specifier) {
            auto *symbol = new Struct_Def_Symbol(get_type(p_struct_specifier));

            insert(symbol);
        }
    }

    void Local_Resolver::visit(Def_Node *node) {
        auto info = get_info(node);
        Type *specifier_type = info.first;

        for (VarDec_Node *var_dec: *info.second) {
            Type *type = specifier_type;
            string id = var_dec->get_id();

            if (!var_dec->is_atomic()) {
                type = new Array_Type(specifier_type, dynamic_cast <Array_VarDec_Node *>(var_dec));
            }

            insert(new Variable_Symbol(id, type));
        }
    }

    bool Local_Resolver::check_struct_def(Symbol_Entry *entry) {
        return entry != nullptr && dynamic_cast<Struct_Def_Symbol *>(entry) != nullptr;

    }

    Type *Local_Resolver::get_type(Specifier_Node *node) {
        if (node->type) {
            return new Primitive_Type(node->type);
        }

        //Struct specifier
        StructSpecifier_Node *struct_node = node->struct_specifier;
        string name = struct_node->id->get_lexeme();
        if (struct_node->def_list) {
            return get_type(struct_node);
        } else if (Symbol_Entry *entry = current_scope()->lookup(name); check_struct_def(entry)) {
            //Found in scope and is a struct def
            return dynamic_cast<Struct_Def_Symbol *>(entry)->struct_type;
        } else {
            //Not found or not a struct def type
            add_error(new Semantic_Error16(node->propagate_line_no(), name));
            return nullptr;
        }
    }

    Type *Local_Resolver::get_type(Type *type, VarDec_Node *var_dec) {
        if (!var_dec->is_atomic()) {
            type = new Array_Type(type, dynamic_cast <Array_VarDec_Node *>(var_dec));
        }

        return type;
    }


    std::pair<Type *, std::vector<VarDec_Node *> *> Local_Resolver::get_info(Def_Node *node) {
        auto specifier_type = get_type(node->specifier);
        auto *decs = new std::vector<VarDec_Node *>{};

        DecList_Node *dec_list = node->dec_list;
        while (dec_list) {
            decs->push_back(dec_list->dec->var_dec);
            dec_list = dec_list->dec_list;
        }

        return make_pair(specifier_type, decs);
    }

    Variable_Symbol *Local_Resolver::get_var_symbol(Type *specifier_type, VarDec_Node *var_dec) {
        Type *type = get_type(specifier_type, var_dec);
        int line_no = var_dec->line_no;
        string id = var_dec->get_id();
        return new Variable_Symbol(type, id, line_no);
    }

    Struct_Type *Local_Resolver::get_type(StructSpecifier_Node *node) {
        string struct_id = node->id->get_lexeme();
        int line_no = node->propagate_line_no();
        vector<pair<string, Type *>> member_vector;

        if (node->def_list == nullptr) {
            //struct without member defined
            add_error(new Semantic_Error17(line_no, struct_id));
            return nullptr;
        }

        // Read def_list into member_vector.
        DefList_Node *def_list = node->def_list;
        while (!def_list->is_empty()) {
            auto info = get_info(def_list->def);
            Type *specifier_type = info.first;
            for (VarDec_Node *var_dec: *info.second) {
                Type *type = specifier_type;
                string id = var_dec->get_id();

                if (!var_dec->is_atomic()) {
                    type = new Array_Type(specifier_type, dynamic_cast <Array_VarDec_Node *>(var_dec));
                }

                member_vector.emplace_back(id, type);
            }

            def_list = def_list->def_list;
        }

        return new Struct_Type(struct_id, line_no, member_vector);
    }

    Function_Symbol *Local_Resolver::get_fun_symbol(Type *return_type, FunDec_Node *fun_dec) {
        string name = fun_dec->id->get_lexeme();
        int line_no = fun_dec->propagate_line_no();
        vector<Type *> parameter_v;

        auto var_list = fun_dec->var_list;
        while (var_list) {
            auto param_dec = var_list->param_dec;
            auto type = get_type(param_dec->specifier);
            parameter_v.push_back(get_type(type, param_dec->var_dec));

            var_list = var_list->var_list;
        }

        return new Function_Symbol(return_type, name, line_no, parameter_v);
    }

    void Dereference_Checker::check(AST *ast) {
        visit(ast->program);
    }

    void Dereference_Checker::visit(CompSt_Node *node) {
        push_scope(node->local_scope);
        Visitor::visit(node);
        pop_scope();
    }

    void Dereference_Checker::pop_scope() {
        scope_stack.pop_back();
    }

    Dereference_Checker::Dereference_Checker(Global_Symbol_Table *top_scope) {
        scope_stack.push_back(top_scope);
    }


    void Dereference_Checker::visit(Exp_Stmt_Node *node) {
        Visitor::visit(node);
    }

    void Dereference_Checker::visit(CompSt_Stmt_Node *node) {
        Visitor::visit(node);
    }

    void Dereference_Checker::visit(Return_Stmt_Node *node) {
        Exp_Info *exp_info = get_info(node->exp);
        if (!exp_info->is_known()) {
            return;
        }

        if (!exp_info->exp_type->compassionate(current_return_type)) {
            add_error(new Semantic_Error8(node->propagate_line_no()));
        }
    }

    void Dereference_Checker::visit(If_Stmt_Node *node) {
        Visitor::visit(node);
    }

    void Dereference_Checker::visit(While_Stmt_Node *node) {
        Visitor::visit(node);
    }

    void Dereference_Checker::visit(Dec_Node *node) {
        Visitor::visit(node);
    }

    void Dereference_Checker::visit(Leaf_Node *node) {
        Visitor::visit(node);
    }

    Exp_Info *Dereference_Checker::get_info(Exp_Node *exp_node) {
        Exp_Info *result = new Unknown_Exp_Info();
        type_case(exp_node,
                  [&](Parentheses_Exp_Node *node) {
                      result = visit(dynamic_cast<Parentheses_Exp_Node *>(exp_node));
                  },
                  [&](ID_Parentheses_Exp_Node *node) {
                      result = visit(dynamic_cast<ID_Parentheses_Exp_Node *>(exp_node));
                  },
                  [&](Bracket_Exp_Node *node) {
                      result = visit(dynamic_cast<Bracket_Exp_Node *>(exp_node));
                  },
                  [&](Dot_Exp_Node *node) {
                      result = visit(dynamic_cast<Dot_Exp_Node *>(exp_node));
                  },
                  [&](Binary_Exp_Node *node) {
                      result = visit(dynamic_cast<Binary_Exp_Node *>(exp_node));
                  },
                  [&](Unary_Exp_Node *node) {
                      result = visit(dynamic_cast<Unary_Exp_Node *>(exp_node));
                  },
                  [&](Leaf_Exp_Node *node) {
                      result = visit(dynamic_cast<Leaf_Exp_Node *>(exp_node));
                  }
        );
        return result;
    }

    Exp_Info *Dereference_Checker::visit(Leaf_Exp_Node *node) {
        int error_line_no = node->propagate_line_no();
        Leaf_Node *leaf = node->leaf;
        token_type leaf_token = leaf->leaf_type;
        switch (leaf_token) {
            case token_type::ID: {
                string var_name = leaf->get_lexeme();
                auto *entry = current_scope()->lookup(var_name);
                //Can not be func symbol
                auto func_type = dynamic_cast<Function_Symbol *>(entry);
                if (func_type != nullptr) {
                    add_error(new Semantic_Error1(error_line_no, var_name));
                    return new Unknown_Exp_Info();
                }

                if (entry == nullptr) {
                    add_error(new Semantic_Error1(error_line_no, var_name));
                    return new Unknown_Exp_Info();
                }

                return new Exp_Info(entry->get_type(), false);
            }
                break;
            case token_type::INT:
            case token_type::FLOAT:
            case token_type::CHAR: {
                Type *type = new Primitive_Type(leaf_token);

                return new Exp_Info(type, true);
            }
                break;
            default:
                cout << "Default case! Error!" << endl;
                return new Unknown_Exp_Info();
        }
    }

    Exp_Info *Dereference_Checker::visit(Binary_Exp_Node *node) {
        Exp_Info *l_info = get_info(node->left);
        Exp_Info *r_info = get_info(node->right);

        if (!l_info->is_known() || !r_info->is_known()) {
            return new Unknown_Exp_Info();
        }

        int error_line_no = node->op_node->propagate_line_no();
        token_type operator_type = node->op_node->leaf_type;
        switch (operator_type) {
            case token_type::ASSIGN: {
                if (l_info->is_rvalue()) {
                    add_error(new Semantic_Error6(error_line_no));
                    return new Unknown_Exp_Info();
                }

                if (!l_info->compassionate(r_info)) {
                    add_error(new Semantic_Error5(error_line_no));
                    return new Unknown_Exp_Info();
                }

                return new Exp_Info(l_info->exp_type, true);
            }
                break;
            case token_type::AND:
            case token_type::OR:
            case token_type::LT:
            case token_type::LE:
            case token_type::GT:
            case token_type::GE:
            case token_type::NE:
            case token_type::EQ:
            case token_type::PLUS:
            case token_type::MINUS:
            case token_type::MUL:
            case token_type::DIV: {
                if (!l_info->compassionate(r_info)) {
                    add_error(new Semantic_Error7(error_line_no));
                    return new Unknown_Exp_Info();
                }
                break;
            }
            default:
                cout << "No other op_token!!!" << endl;
        }

        // Bool operator or arithmetic operator and they're compatible with each other
        Type *integration_type = merge_type(dynamic_cast<Primitive_Type *>(l_info->exp_type),
                                            dynamic_cast<Primitive_Type *>(r_info->exp_type));

        return new Exp_Info(integration_type, true);
    }


    Exp_Info *Dereference_Checker::visit(Unary_Exp_Node *node) {
        auto *exp_info = get_info(node->exp_node);
        if (!exp_info->is_known()) {
            return new Unknown_Exp_Info();
        }

        if (auto p_type = dynamic_cast<Primitive_Type *>(exp_info->exp_type); p_type == nullptr) {
            add_error(new Semantic_Error7(node->op_node->propagate_line_no()));
            return new Unknown_Exp_Info();
        }

        return exp_info;
    }

    Exp_Info *Dereference_Checker::visit(Parentheses_Exp_Node *node) {
        return get_info(node->exp);
    }

    Exp_Info *Dereference_Checker::visit(ID_Parentheses_Exp_Node *node) {
        int error_line_no = node->propagate_line_no();
        string func_name = node->id->get_lexeme();
        Symbol_Entry *entry = current_scope()->lookup(func_name);
        auto func_entry = dynamic_cast<Function_Symbol *>(entry);
        if (entry == nullptr) {
            add_error(new Semantic_Error2(error_line_no, func_name));
            return new Unknown_Exp_Info();
        } else if (func_entry == nullptr) {
            add_error(new Semantic_Error11(error_line_no));
            return new Unknown_Exp_Info();
        }

        auto func_parameters = func_entry->get_parameters();

        vector<Type *> args_types;
        Args_Node *args = node->args;
        while (args) {
            Exp_Info *arg_info = get_info(args->exp);
            if (!arg_info->is_known()) {
                return new Unknown_Exp_Info();
            }

            args_types.push_back(arg_info->exp_type);

            args = args->args;
        }

        if (func_parameters.size() != args_types.size()) {
            add_error(new Semantic_Error9(error_line_no));
            return new Unknown_Exp_Info();
        }

        for (int i = 0, sz = func_parameters.size(); i < sz; ++i) {
            if (!func_parameters[i]->compassionate(args_types[i])) {
                add_error(new Semantic_Error9(error_line_no));
                return new Unknown_Exp_Info();
            }
        }

        return new Exp_Info(func_entry->get_type(), true);
    }

    Exp_Info *Dereference_Checker::visit(Bracket_Exp_Node *node) {
        int error_line_no = node->propagate_line_no();

        Exp_Info *exp1_info = get_info(node->exp1);
        Exp_Info *exp2_info = get_info(node->exp2);
        if (!exp1_info->is_known() || !exp2_info->is_known()) {
            return new Unknown_Exp_Info();
        }

        auto int_type = dynamic_cast<Primitive_Type *>(exp2_info->exp_type);
        if (int_type == nullptr || int_type->type != primitive_type::INT) {
            add_error(new Semantic_Error12(error_line_no));
            return new Unknown_Exp_Info();
        }

        auto array_type = dynamic_cast<Array_Type *>(exp1_info->exp_type);
        if (array_type == nullptr) {
            add_error(new Semantic_Error10(error_line_no));
            return new Unknown_Exp_Info();
        }

        auto *new_type = array_type->reduce_dim();

        return new Exp_Info(new_type, false);
    }

    Exp_Info *Dereference_Checker::visit(Dot_Exp_Node *node) {
        int error_line_no = node->propagate_line_no();

        auto *exp_info = get_info(node->exp);
        if (!exp_info->is_known()) {
            return new Unknown_Exp_Info();
        }

        auto *struct_type = dynamic_cast<Struct_Type *>(exp_info->exp_type);
        if (struct_type == nullptr) {
            add_error(new Semantic_Error13(error_line_no));
            return new Unknown_Exp_Info();
        }

        string member_id = node->id->get_lexeme();
        if (!struct_type->contains(member_id)) {
            add_error(new Semantic_Error14(error_line_no));
            return new Unknown_Exp_Info;
        }

        return new Exp_Info(struct_type->members[member_id], false);
    }

    Type *Dereference_Checker::merge_type(Primitive_Type *lhs, Primitive_Type *rhs) {
        if (lhs->type == primitive_type::CHAR) {
            return lhs;
        } else if (lhs->type == primitive_type::FLOAT) {
            return lhs;
        } else if (rhs->type == primitive_type::FLOAT) {
            return rhs;
        } else {
            return lhs;
        }
    }

    void Dereference_Checker::visit(ExtDef_Node *node) {
        if (node->fun_dec) {
            string func_id = node->fun_dec->id->get_lexeme();
            Symbol_Entry *entry = current_scope()->lookup(func_id);
            auto *func_entry = dynamic_cast<Function_Symbol *>(entry);
            if (func_entry == nullptr || node->propagate_line_no() != entry->line_no) {
                this->current_return_type = nullptr;
                return;
            }

            this->current_return_type = func_entry->get_type();
        }

        Visitor::visit(node);
    }

    void Semantic_Checker::add_error(Semantic_Error *error) {
        errors.push_back(error);
    }

    Symbol_Table *Semantic_Checker::current_scope() {
        return scope_stack.back();
    }

    Global_Symbol_Table *Semantic_Checker::top_scope() {
        return dynamic_cast<Global_Symbol_Table *>(scope_stack[0]);
    }

    void Semantic_Checker::push_scope(Local_Symbol_Table *local_scope) {
        scope_stack.push_back(local_scope);
    }

    std::vector<Error *> Semantic_Checker::get_errors() {
        return errors;
    }
}