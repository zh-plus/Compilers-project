//
// Created by 10578 on 10/10/2019.
//

#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <algorithm>
#include <functional>
#include <locale>
#include <string>
#include "parser.tab.hpp"

namespace SPL {
    using token = SPL::SPL_Parser::token;

    static std::unordered_map<int, std::string> symbol_map{
            {token::DOT,    "DOT"},
            {token::SEMI,   "SEMI"},
            {token::COMMA,  "COMMA"},
            {token::EQ,     "EQ"},
            {token::ASSIGN, "ASSIGN"},
            {token::LE,     "LE"},
            {token::LT,     "LT"},
            {token::GE,     "GT"},
            {token::GT,     "GT"},
            {token::NE,     "NE"},
            {token::NOT,    "NOT"},
            {token::PLUS,   "PLUS"},
            {token::MINUS,  "MINUS"},
            {token::MUL,    "MUL"},
            {token::DIV,    "DIV"},
            {token::AND,    "AND"},
            {token::OR,     "OR"},
            {token::LP,     "LP"},
            {token::RP,     "RP"},
            {token::LC,     "LC"},
            {token::RC,     "RC"},
            {token::LB,     "LB"},
            {token::RB,     "RB"},
    };

    std::string trim(const std::string &str, const std::string &ws);
}

#endif //COMPILERS_UTIL_HPP
