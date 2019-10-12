//
// Created by 10578 on 10/9/2019.
//

#include <cctype>
#include <fstream>
#include <cassert>
#include <iostream>
#include <algorithm>

#include "spl_driver.hpp"

namespace SPL {

    SPL_Driver::~SPL_Driver() {
        delete (scanner);
        scanner = nullptr;
        delete (parser);
        parser = nullptr;
    }

    void SPL_Driver::parse(const char *filename) {
        assert(filename != nullptr);
        std::ifstream in_file(filename);

        if (not in_file.good()) {
            exit(EXIT_FAILURE);
        }

        parse_helper(in_file);
    }

    void SPL_Driver::parse(std::istream &is) {
        if (not is.good()) {
            exit(EXIT_FAILURE);
        } else if (is.eof()) {
            exit(EXIT_SUCCESS);
        }

        parse_helper(is);
    }

    void SPL_Driver::parse_helper(std::istream &is) {
        delete (scanner);
        try {
            scanner = new SPL_Scanner(&is);
        } catch (std::bad_alloc &bad_alloc) {
            std::cerr << "Failed to allocate scanner: (" << bad_alloc.what() << ")!" << std::endl;
            exit(EXIT_FAILURE);
        }

        delete (parser);
        try {
            parser = new SPL_Parser(*scanner, *this);
        } catch (std::bad_alloc &bad_alloc) {
            std::cerr << "Parse Failed!" << std::endl;
            exit(EXIT_FAILURE);
        }

        try {
            parser->parse();
        } catch (const SPL_Parser::syntax_error &e) {
            exit(EXIT_FAILURE);
        }
    }

    void SPL_Driver::set_root(Program_Node *node) {
        root = node;
    }

    Program_Node *SPL_Driver::get_root() {
        return root;
    }

    SPL_Scanner *SPL_Driver::get_scanner() {
        return scanner;
    }

}
