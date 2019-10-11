//
// Created by 10578 on 10/9/2019.
//

#ifndef ___SPL_DRIVER_HPP__
#define ___SPL_DRIVER_HPP__

#include <string>
#include <cstddef>
#include <istream>
#include <unordered_map>

#include "ast.hpp"
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

        void set_root(SPL::Program_Node *node);

        SPL::Program_Node * get_root();

        void scan_int(const int &number);

        void scan_float(const float &number);

        void scan_type(const std::string &type_word);

        void scan_keyword(const std::string &keyword);

        void scan_id(const std::string &id);

        void scan_symbol(const int &id);

        void scan_line_comment(const std::string &line_comment);

    private:
        void parse_helper(std::istream &is);

        SPL::SPL_Parser *parser = nullptr;
        SPL::SPL_Scanner *scanner = nullptr;

        SPL::Program_Node *root = nullptr;

        /* define some pretty colors */
        const std::string red = "\033[1;31m";
        const std::string blue = "\033[1;36m";
        const std::string norm = "\033[0m";
    };

}

#endif //END ___SPL_DRIVER_HPP__
