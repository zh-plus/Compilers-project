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

void SPL::SPL_Driver::scan_int(const int &number) {
    std::cout << "INT " << number << std::endl;
}

void SPL::SPL_Driver::scan_float(const float &number) {
    std::cout << "FLOAT " << number << std::endl;
}

void SPL::SPL_Driver::scan_type(const std::string &type_word) {
    std::cout << "TYPE " << type_word << std::endl;
}

void SPL::SPL_Driver::scan_keyword(const std::string &keyword) {
    std::string upper_str = keyword;
    std::transform(upper_str.begin(), upper_str.end(), upper_str.begin(), ::toupper);
    std::cout << upper_str << std::endl;
}

void SPL::SPL_Driver::scan_id(const std::string &id) {
    std::cout << "ID " << id << std::endl;
}

void SPL::SPL_Driver::scan_symbol(const int &symbol) {
    std::cout << symbol_map[symbol] << std::endl;
}

void SPL::SPL_Driver::scan_line_comment(const std::string &line_comment) {
    std::cout << "Line comment: " << line_comment;
}