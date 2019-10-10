//
// Created by 10578 on 10/9/2019.
//

#ifndef __AST_HPP__
#define __AST_HPP__

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <variant>
#include "parser.tab.hpp"
#include "utils.hpp"

/**
 * Abstract syntax tree of SUSTech Programming Language.
 */

namespace SPL {
    using token_type = SPL_Parser::token_type;
    using token = SPL_Parser::token;



    class AST_Node {
    public:
        virtual ~AST_Node() = default;

        virtual std::string to_string() = 0;

        virtual std::vector<AST_Node *> get_child() = 0;
    };

    class ASSIGN_Node : public AST_Node {
    public:
        std::string id;
        int value;

        ~ASSIGN_Node() override = default;

        ASSIGN_Node(std::string id, int value) : id{id}, value{value} {};

        std::string to_string() override;

        std::vector<AST_Node *> get_child() override;
    };

    class ARGS_Node : public AST_Node {
    public:
        std::string id;
        int value;

        std::vector<std::string> arg_list;

        ~ARGS_Node() override = default;

        ARGS_Node(std::string id, int value) : id{id}, value{value}, arg_list{id} {};

        void push_back(const std::string &id);

        std::string to_string() override;

        std::vector<AST_Node *> get_child() override;
    };

    class Leaf_Node : public AST_Node {
    public:
        token_type leaf_type;
        std::string lexeme;
        std::variant<int, float, char, std::string> value;

        Leaf_Node(token_type leaf_type, std::string lexeme);

        std::string to_string() override;

        std::vector<AST_Node *> get_child() override;
    };

    class EXP_Node : public AST_Node {
    public:

    };

    class Binary_EXP_Node : public EXP_Node {
    public:
        token_type op_type;
        EXP_Node *left;
        EXP_Node *right;

        Binary_EXP_Node(token_type op_type, EXP_Node *left, EXP_Node *right) : op_type{op_type},
                                                                               left{left},
                                                                               right{right} {};

        std::string to_string() override;

        std::vector<AST_Node *> get_child() override;
    };

    class Unary_EXP_Node : public EXP_Node {
    public:
        token_type op_type;
        EXP_Node *node;

        Unary_EXP_Node(token_type op_type, EXP_Node *node) : op_type{op_type}, node{node} {};

        Unary_EXP_Node(token_type op_type, std::string test_msg);

        std::string to_string() override;

        std::vector<AST_Node *> get_child() override;
    };

    class Leaf_EXP_Node : public EXP_Node {
    public:
        Leaf_Node *leaf_node;

        explicit Leaf_EXP_Node(Leaf_Node *leaf_node) : leaf_node{leaf_node} {};

        explicit Leaf_EXP_Node(token_type leaf_type, std::string lexeme);

        std::string to_string() override;

        std::vector<AST_Node *> get_child() override;
    };

    void print_ast(AST_Node *node, int indent_level = 0);
}


#endif //__AST_HPP__
