//
// Created by 10578 on 10/9/2019.
//

#ifndef ___SPL_DRIVER_HPP__
#define ___SPL_DRIVER_HPP__

#include <string>
#include <cstddef>
#include <istream>

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

        void add_upper();

        void add_lower();

        void add_word(const std::string &word);

        void add_newline();

        void add_char();

        std::ostream &print(std::ostream &os);

    private:
        void parse_helper(std::istream &is);

        std::size_t chars = 0;
        std::size_t words = 0;
        std::size_t lines = 0;
        std::size_t uppercase = 0;
        std::size_t lowercase = 0;

        SPL::SPL_Parser *parser = nullptr;
        SPL::SPL_Scanner *scanner = nullptr;

        /* define some pretty colors */
        const std::string red = "\033[1;31m";
        const std::string blue = "\033[1;36m";
        const std::string norm = "\033[0m";
    };

}

#endif //END ___SPL_DRIVER_HPP__