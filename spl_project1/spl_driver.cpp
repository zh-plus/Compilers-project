//
// Created by 10578 on 10/9/2019.
//

#include <cctype>
#include <fstream>
#include <cassert>
#include <iostream>
#include <algorithm>

#include "spl_driver.hpp"

SPL::SPL_Driver::~SPL_Driver() {
    delete (scanner);
    scanner = nullptr;
    delete (parser);
    parser = nullptr;
}

void SPL::SPL_Driver::parse(const char *filename) {
    assert(filename != nullptr);
    std::ifstream in_file(filename);

    if (not in_file.good()) {
        exit(EXIT_FAILURE);
    }

    parse_helper(in_file);
}

void SPL::SPL_Driver::parse(std::istream &is) {
    if (not is.good()) {
        exit(EXIT_FAILURE);
    } else if (is.eof()) {
        exit(EXIT_SUCCESS);
    }

    parse_helper(is);
}

void SPL::SPL_Driver::parse_helper(std::istream &is) {
    delete (scanner);
    try {
        scanner = new SPL::SPL_Scanner(&is);
    } catch (std::bad_alloc &bad_alloc) {
        std::cerr << "Failed to allocate scanner: (" << bad_alloc.what() << ")!" << std::endl;
        exit(EXIT_FAILURE);
    }

    delete (parser);
    try {
        parser = new SPL::SPL_Parser(*scanner, *this);
    } catch (std::bad_alloc &bad_alloc) {
        std::cerr << "Parse Failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    const int accept = 0;
    if (parser->parse() != accept) {
        std::cerr << "Parse failed!" << std::endl;
    }
}

void SPL::SPL_Driver::set_root(SPL::Program_Node *node) {
    root = node;
}

SPL::Program_Node * SPL::SPL_Driver::get_root() {
    return root;
}

SPL::SPL_Scanner *SPL::SPL_Driver::get_scanner() {
    return scanner;
}
