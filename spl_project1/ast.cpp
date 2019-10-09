//
// Created by 10578 on 10/9/2019.
//

#include "ast.hpp"

SPL::ASSIGN_Node::~ASSIGN_Node() = default;

SPL::AST_Node::~AST_Node() = default;

SPL::ARGS_Node::~ARGS_Node() = default;

void SPL::ARGS_Node::push_back(std::string id) {
    list.push_back(id);
}