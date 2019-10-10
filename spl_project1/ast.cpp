//
// Created by 10578 on 10/9/2019.
//

#include "ast.hpp"

namespace SPL {

    void ARGS_Node::push_back(const std::string &str) {
        std::cout << "In push back succeed!" << std::endl;
        arg_list.push_back(str);
    }

    std::string ARGS_Node::to_string() {
        return "ARGS";
    }

    std::vector<AST_Node *> ARGS_Node::get_child() {
        return std::vector<AST_Node *>();
    }

    Leaf_Node::Leaf_Node(token_type leaf_type, std::string lexeme) {
        this->leaf_type = leaf_type;
        this->lexeme = lexeme;

        switch (this->leaf_type) {
            case token::INT:
                this->value = std::stoi(this->lexeme, nullptr, 0);
                break;
            case token::FLOAT:
                this->value = std::stoi(this->lexeme, nullptr, 0);
                break;
            case token::CHAR:
                this->value = trim(this->lexeme, "'").c_str()[0];
                break;
            default:
                break;
        }
    }

    std::string Leaf_Node::to_string() {
        return lexeme;
    }

    std::vector<AST_Node *> Leaf_Node::get_child() {
        return std::vector<AST_Node *>();
    }

    Unary_EXP_Node::Unary_EXP_Node(token_type op_type, std::string test_msg) {
        this->op_type = op_type;
        this->node = nullptr;

        std::cout << test_msg << std::endl;
    }

    std::string Unary_EXP_Node::to_string() {
        return symbol_map[this->op_type];
    }

    std::vector<AST_Node *> Unary_EXP_Node::get_child() {
        return std::vector<AST_Node *>{node};
    }

    Leaf_EXP_Node::Leaf_EXP_Node(token_type leaf_type, std::string lexeme) {
        this->leaf_node = new Leaf_Node(leaf_type, lexeme);
    }

    std::string Leaf_EXP_Node::to_string() {
        return leaf_node->to_string();
    }

    std::vector<AST_Node *> Leaf_EXP_Node::get_child() {
        return std::vector<AST_Node *>();
    }

    std::string ASSIGN_Node::to_string() {
        return "ASSIGN";
    }

    std::vector<AST_Node *> ASSIGN_Node::get_child() {
        return std::vector<AST_Node *>();
    }

    std::string Binary_EXP_Node::to_string() {
        //TODO: Change into symbol_map[op_type]
        return left->to_string() + " " + symbol_map[op_type] + " " + right->to_string();
    }

    std::vector<AST_Node *> Binary_EXP_Node::get_child() {
        return std::vector<AST_Node *>{left, right};
    }

    void print_ast(AST_Node *node, int indent_level) {
        std::cout << node->to_string() << std::endl;
    }
}
