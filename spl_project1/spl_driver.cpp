//
// Created by 10578 on 10/9/2019.
//

#include <cctype>
#include <fstream>
#include <cassert>
#include <iostream>

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

void SPL::SPL_Driver::add_upper() {
    uppercase++;
    chars++;
    words++;
}

void SPL::SPL_Driver::add_lower() {
    lowercase++;
    chars++;
    words++;
}

void SPL::SPL_Driver::add_word(const std::string &word) {
    words++;
    chars += word.length();
    for (auto &c: word) {
        if (islower(c)) {
            lowercase++;
        } else if (isupper(c)) {
            uppercase++;
        }
    }
}

void SPL::SPL_Driver::add_newline() {
    lines++;
    chars++;
}

void SPL::SPL_Driver::add_char() {
    chars++;
}

std::ostream &SPL::SPL_Driver::print(std::ostream &os) {
    os << red << "Results: " << norm << std::endl;
    os << blue << "Uppercase: " << norm << uppercase << std::endl;
    os << blue << "Lowercase: " << norm << lowercase << std::endl;
    os << blue << "Lines: " << norm << lines << std::endl;
    os << blue << "Words: " << norm << words << std::endl;
    os << blue << "Characters: " << norm << chars;
    return os;
}