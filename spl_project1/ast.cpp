//
// Created by 10578 on 10/9/2019.
//

#include "ast.hpp"

void SPL::ARGS_Node::push_back(const std::string& str) {
    std::cout << "In push back succeed!" << std::endl;
    arg_list.push_back(str);
}

SPL::Leaf_Node::Leaf_Node(SPL::token_type leaf_type, SPL::leaf_union value) {
    leaf_type = leaf_type;

}
