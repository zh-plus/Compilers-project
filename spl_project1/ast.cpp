//
// Created by 10578 on 10/9/2019.
//

#include "ast.hpp"

namespace SPL {

    std::string Args_Node::to_string() {
        return "Args";
    }

    std::vector<AST_Node *> Args_Node::get_child() {
        if (comma && args) {
            return std::vector<AST_Node *>{exp, comma, args};
        } else {
            return std::vector<AST_Node *>{exp};
        }
    }

    Leaf_Node::Leaf_Node(token_type leaf_type, std::string lexeme) {
        this->leaf_type = leaf_type;
        this->lexeme = lexeme;

        switch (this->leaf_type) {
            case token::INT:
                value = std::stoi(this->lexeme, nullptr, 0);
                break;
            case token::FLOAT:
                value = std::stoi(this->lexeme, nullptr, 0);
                break;
            case token::CHAR:
                value = trim(this->lexeme, "'").c_str()[0];
                break;
            default:
                break;
        }
    }

    std::string Leaf_Node::to_string() {
        switch (leaf_type) {
            case token::INT:
                return symbol_map[leaf_type] + ": " + std::to_string(std::get<int>(value));
            case token::FLOAT:
                return symbol_map[leaf_type] + ": " + std::to_string(std::get<float>(value));
            case token::CHAR:
            case token::TYPE:
            case token::ID:
                return symbol_map[leaf_type] + ": " + lexeme;
            default:
                return symbol_map[leaf_type];
        }
    }

    std::vector<AST_Node *> Leaf_Node::get_child() {
        return std::vector<AST_Node *>();
    }

    std::vector<AST_Node *> Unary_Exp_Node::get_child() {
        return std::vector<AST_Node *>{this->op_node, this->node};
    }

    std::vector<AST_Node *> Binary_Exp_Node::get_child() {
        return std::vector<AST_Node *>{this->left, this->op_node, this->right};
    }

    Leaf_Node *make_leaf(token_type leaf_type, std::string lexeme) {
        return new Leaf_Node(leaf_type, lexeme);
    }

    void print_ast(AST_Node *node, int indent_level) {
        if (std::string content = node->to_string(); !content.empty()) {
            std::cout << std::string(2 * indent_level, ' ') // Indent format
                      << content << std::endl;
        }

        for (auto &child: node->get_child()) {
            print_ast(child, indent_level + 1);
        }
    }

    std::string Exp_Node::to_string() {
        return "Exp";
    }

    std::vector<AST_Node *> Parentheses_Exp_Node::get_child() {
        return std::vector<AST_Node *>{this->lp, this->exp, this->rp};
    }

    std::vector<AST_Node *> ID_Parentheses_Exp_Node::get_child() {
        if (args != nullptr) {
            return std::vector<AST_Node *>{id, lp, args, rp};
        } else {
            return std::vector<AST_Node *>{id, lp, rp};
        }
    }

    std::vector<AST_Node *> Bracket_Exp_Node::get_child() {
        return std::vector<AST_Node *>{this->exp1, this->lb, this->exp2, this->rb};
    }

    std::vector<AST_Node *> Dot_Exp_Node::get_child() {
        return std::vector<AST_Node *>{this->exp, this->dot, this->id};
    }

    std::vector<AST_Node *> Leaf_Exp_Node::get_child() {
        return std::vector<AST_Node *>{this->leaf};
    }

    std::string DefList_Node::to_string() {
        return "DefList";
    }

    std::vector<AST_Node *> DefList_Node::get_child() {
        return std::vector<AST_Node *>{this->def, this->def_list};
    }

    std::vector<AST_Node *> Empty_DefList_Node::get_child() {
        return std::vector<AST_Node *>();
    }

    std::string Empty_DefList_Node::to_string() {
        return "";
    }

    std::vector<AST_Node *> Def_Node::get_child() {
        return std::vector<AST_Node *>{this->specifier, this->dec_list, this->semi};
    }

    std::string Def_Node::to_string() {
        return "Def";
    }

    std::string DecList_Node::to_string() {
        return "DecList";
    }

    std::vector<AST_Node *> DecList_Node::get_child() {
        if (comma && dec_list) {
            return std::vector<AST_Node *>{this->dec, comma, dec_list};
        } else {
            return std::vector<AST_Node *>{this->dec};
        }
    }

    std::string Empty_DecList_Node::to_string() {
        return "";
    }

    std::vector<AST_Node *> Empty_DecList_Node::get_child() {
        return std::vector<AST_Node *>();
    }

    std::string Dec_Node::to_string() {
        return "Dec";
    }

    std::vector<AST_Node *> Dec_Node::get_child() {
        if (assign && exp) {
            return std::vector<AST_Node *>{var_dec, assign, exp};
        } else {
            return std::vector<AST_Node *>{var_dec};
        }
    }

    std::string CompSt_Node::to_string() {
        return "CompSt";
    }

    std::vector<AST_Node *> CompSt_Node::get_child() {
        return std::vector<AST_Node *>{lc, def_list, stmt_list, rc};
    }

    std::string Empty_StmtList_Node::to_string() {
        return "";
    }

    std::vector<AST_Node *> Empty_StmtList_Node::get_child() {
        return std::vector<AST_Node *>();
    }

    std::string StmtList_Node::to_string() {
        return "StmtList";
    }

    std::vector<AST_Node *> StmtList_Node::get_child() {
        return std::vector<AST_Node *>{stmt, stmt_list};
    }

    std::string Stmt_Node::to_string() {
        return "Stmt";
    }

    std::vector<AST_Node *> Exp_Stmt_Node::get_child() {
        return std::vector<AST_Node *>{exp, semi};
    }

    std::vector<AST_Node *> CompSt_Stmt_Node::get_child() {
        return std::vector<AST_Node *>{comp_st};
    }

    std::vector<AST_Node *> Return_Stmt_Node::get_child() {
        return std::vector<AST_Node *>{ret, exp, semi};
    }

    std::vector<AST_Node *> If_Stmt_Node::get_child() {
        if (_else && stmt_else) {
            return std::vector<AST_Node *>{_if, lp, exp, rp, stmt_if, _else, stmt_else};
        } else {
            return std::vector<AST_Node *>{_if, lp, exp, rp, stmt_if};
        }

    }

    std::vector<AST_Node *> While_Stmt_Node::get_child() {
        return std::vector<AST_Node *>{_while, lp, exp, rp, stmt};
    }

    std::string VarDec_Node::to_string() {
        return "VarDec";
    }

    std::vector<AST_Node *> ID_VarDec_Node::get_child() {
        return std::vector<AST_Node *>{id};
    }

    std::vector<AST_Node *> Array_VarDec_Node::get_child() {
        return std::vector<AST_Node *>{var_dec, lb, _int, rb};
    }

    std::string FunDec_Node::to_string() {
        return "FunDec";
    }

    std::vector<AST_Node *> FunDec_Node::get_child() {
        if (var_list) {
            return std::vector<AST_Node *>{id, lp, var_list, rp};
        } else {
            return std::vector<AST_Node *>{id, lp, rp};
        }

    }

    std::string VarList_Node::to_string() {
        return "VarList";
    }

    std::vector<AST_Node *> VarList_Node::get_child() {
        if (comma && var_list) {
            return std::vector<AST_Node *>{param_dec, comma, var_list};
        } else {
            return std::vector<AST_Node *>{param_dec};
        }
    }

    std::string ParamDec_Node::to_string() {
        return "ParamDec";
    }

    std::vector<AST_Node *> ParamDec_Node::get_child() {
        return std::vector<AST_Node *>{specifier, var_dec};
    }

    std::string Specifier_Node::to_string() {
        return "Specifier";
    }

    std::vector<AST_Node *> Specifier_Node::get_child() {
        if (type) {
            return std::vector<AST_Node *>{type};
        } else {
            return std::vector<AST_Node *>{struct_specifier};
        }
    }

    std::vector<AST_Node *> StructSpecifier_Node::get_child() {
        if (lc && def_list && rc) {
            return std::vector<AST_Node *>{_struct, id, lc, def_list, rc};
        } else {
            return std::vector<AST_Node *>{_struct, id};
        }
    }

    std::string StructSpecifier_Node::to_string() {
        return "StructSpecifier";
    }

    std::string Program_Node::to_string() {
        return "Program";
    }

    std::vector<AST_Node *> Program_Node::get_child() {
        return std::vector<AST_Node *>{ext_def_list};
    }

    std::string ExtDefList_Node::to_string() {
        return "ExtDefList";
    }

    std::vector<AST_Node *> ExtDefList_Node::get_child() {
        return std::vector<AST_Node *>{ext_def, ext_def_list};
    }

    std::string Empty_ExtDefList_Node::to_string() {
        return "";
    }

    std::vector<AST_Node *> Empty_ExtDefList_Node::get_child() {
        return std::vector<AST_Node *>{};
    }

    std::string ExtDef_Node::to_string() {
        return "ExtDef";
    }

    std::vector<AST_Node *> ExtDef_Node::get_child() {
        if (ext_dec_list) {
            return std::vector<AST_Node *>{specifier, ext_dec_list, semi};
        } else if (fun_dec && comp_st) {
            return std::vector<AST_Node *>{specifier, fun_dec, comp_st};
        } else {
            return std::vector<AST_Node *>{specifier, semi};
        }
    }

    std::string ExtDecList_Node::to_string() {
        return "ExtDecList";
    }

    std::vector<AST_Node *> ExtDecList_Node::get_child() {
        if (comma && ext_dec_list) {
            return std::vector<AST_Node *>{var_dec, comma, ext_dec_list};
        } else {
            return std::vector<AST_Node *>{var_dec};
        }
    }
}