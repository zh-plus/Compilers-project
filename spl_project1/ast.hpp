//
// Created by 10578 on 10/9/2019.
//

#ifndef __AST_HPP__
#define __AST_HPP__

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "parser.tab.hpp"

/**
 * Abstract syntax tree of SUSTech Programming Language.
 */

namespace SPL {
    using token_type = SPL_Parser::token_type;

    union leaf_union {
        int i;
        float f;
        std::string *s;
        char c;
    };

    class AST_Node {
    public:
        virtual ~AST_Node() = default;
    };

    class ASSIGN_Node : AST_Node {
    public:
        ~ASSIGN_Node() override = default;

        ASSIGN_Node(std::string id, int value) : id{std::move(id)}, value{value} {};

    private:
        std::string id;
        int value;
    };

    class ARGS_Node : AST_Node {
    public:
        std::vector<std::string> arg_list;

        ~ARGS_Node() override = default;

        ARGS_Node(std::string id, int value) : id{std::move(id)}, value{value}, arg_list{id} {};

        void push_back(const std::string &id);

    private:
        std::string id;
        int value;
    };

    class Leaf_Node : AST_Node {
    public:
        explicit Leaf_Node(token_type leaf_type, leaf_union value);

    private:
        token_type leaf_type;
        leaf_union value;
    };

    class EXP_Node : AST_Node {
    public:

    };

    class Binary_EXP_Node : EXP_Node {
    public:
        Binary_EXP_Node(token_type op_type, EXP_Node *left, EXP_Node *right) : op_type{op_type},
                                                                               left{left},
                                                                               right{right} {};

    private:
        token_type op_type;
        EXP_Node *left;
        EXP_Node *right;
    };

    class Unary_EXP_Node : EXP_Node {
    public:
        Unary_EXP_Node(token_type op_type, EXP_Node *node) : op_type{op_type}, node{node} {};

    private:
        token_type op_type;
        EXP_Node *node;
    };

    class Leaf_EXP_Node : EXP_Node {
    public:
        explicit Leaf_EXP_Node(Leaf_Node *leaf_node) : leaf_node{leaf_node} {};

    private:
        Leaf_Node *leaf_node;
    };
}


#endif //__AST_HPP__
