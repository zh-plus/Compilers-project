//
// Created by 10578 on 10/9/2019.
//

#ifndef ___SPL_DRIVER_HPP__
#define ___SPL_DRIVER_HPP__

#include <string>
#include <cstddef>
#include <istream>
#include <unordered_map>

#include "scanner.hpp"
#include "parser.tab.hpp"

namespace SPL {

    class SPL_Driver {
    public:
        SPL_Driver() = default;

        virtual ~SPL_Driver();

        /**
         * Parse from a file.
         * @param filename - string of input file
         */
        void parse(const char *filename);

        void parse(std::istream &is);

        void scan_int(const int &number);

        void scan_float(const float &number);

        void scan_type(const std::string &type_word);

        void scan_keyword(const std::string &keyword);

        void scan_id(const std::string &id);

        void scan_symbol(const int &id);

        void scan_line_comment(const std::string &line_comment);

    private:
        void parse_helper(std::istream &is);

        std::unordered_map<int, std::string> symbol_map{
                {SPL::SPL_Parser::token::DOT, "DOT"},
                {SPL::SPL_Parser::token::SEMI, "SEMI"},
                {SPL::SPL_Parser::token::COMMA, "COMMA"},
                {SPL::SPL_Parser::token::EQ, "EQ"},
                {SPL::SPL_Parser::token::ASSIGN, "ASSIGN"},
                {SPL::SPL_Parser::token::LE, "LE"},
                {SPL::SPL_Parser::token::LT, "LT"},
                {SPL::SPL_Parser::token::GE, "GT"},
                {SPL::SPL_Parser::token::GT, "GT"},
                {SPL::SPL_Parser::token::NE, "NE"},
                {SPL::SPL_Parser::token::NOT, "NOT"},
                {SPL::SPL_Parser::token::ADD, "ADD"},
                {SPL::SPL_Parser::token::MINUS, "MINUS"},
                {SPL::SPL_Parser::token::MUL, "MUL"},
                {SPL::SPL_Parser::token::DIV, "DIV"},
                {SPL::SPL_Parser::token::AND, "AND"},
                {SPL::SPL_Parser::token::OR, "OR"},
                {SPL::SPL_Parser::token::LP, "LP"},
                {SPL::SPL_Parser::token::RP, "RP"},
                {SPL::SPL_Parser::token::LC, "LC"},
                {SPL::SPL_Parser::token::RC, "RC"},
                {SPL::SPL_Parser::token::LB, "LB"},
                {SPL::SPL_Parser::token::RB, "RB"},
        };

        SPL::SPL_Parser *parser = nullptr;
        SPL::SPL_Scanner *scanner = nullptr;

        /* define some pretty colors */
        const std::string red = "\033[1;31m";
        const std::string blue = "\033[1;36m";
        const std::string norm = "\033[0m";
    };

}

#endif //END ___SPL_DRIVER_HPP__
