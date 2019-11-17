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

    void Local_Resolver::push_scope(Local_Symbol_Table *local_scope) {
        scope_stack.push_back(local_scope);
    }

    Symbol_Table *Local_Resolver::current_scope() {
        return scope_stack.back();
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
                          cout << "is Variable_Symbol!" << endl;
                          add_error(new Semantic_Error3(entry->line_no, defined_line, name));
                      },
                      [&](Struct_Def_Symbol *symbol) {
                          cout << "is Struct_Def_Symbol!" << endl;
                          add_error(new Semantic_Error15(entry->line_no, defined_line, name));
                      },
                      [&](Function_Symbol *symbol) {
                          cout << "is Function_Symbol!" << endl;
                          add_error(new Semantic_Error4(entry->line_no, defined_line, name));
                      });

        } else {
            current_scope()->insert(entry);
        }
    }

    void Local_Resolver::add_error(Semantic_Error *error) {
        errors.push_back(error);
    }

    std::vector<Error *> Local_Resolver::get_errors() {
        return errors;
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
        cout << "Visiting ExtDef_Node!" << endl;
        Type *specifier_type = get_type(node->specifier);
        if (node->ext_dec_list) {
            cout << "    ext_dec_list" << endl;
            auto *t_ext_dec_list = node->ext_dec_list;
            while (t_ext_dec_list) {
                auto var_symbol = get_var_symbol(specifier_type, t_ext_dec_list->var_dec);
                insert(var_symbol);

                t_ext_dec_list = t_ext_dec_list->ext_dec_list;
            }
        } else if (node->fun_dec) {
            cout << "    fun_dec" << endl;
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
            cout << "    struct_specifier" << endl;
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

    void Dereference_Checker::push_scope(Local_Symbol_Table *local_scope) {
        scope_stack.push_back(local_scope);
    }

    void Dereference_Checker::pop_scope() {
        scope_stack.pop_back();
    }

    Symbol_Table *Dereference_Checker::current_scope() {
        return scope_stack.back();
    }

    Exp_Info Dereference_Checker::visit(Binary_Exp_Node *node) {


        Visitor::visit(node);
    }
}