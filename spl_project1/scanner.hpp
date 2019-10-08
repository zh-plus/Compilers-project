//
// Created by 10578 on 10/9/2019.
//

#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__

#if !defined(yyFlexLexerOnce)

#include <FlexLexer.h>

#endif

#include "parser.tab.hpp"
#include "location.hh"

namespace SPL {

    class SPL_Scanner : public yyFlexLexer {
    public:

        SPL_Scanner(std::istream *in) : yyFlexLexer(in) {
            loc = new SPL::SPL_Parser::location_type();
        };

        //get rid of override virtual function warning
        using FlexLexer::yylex;

        virtual
        int yylex(SPL::SPL_Parser::semantic_type *const lval,
                  SPL::SPL_Parser::location_type *location);
        // YY_DECL defined in scanner.l
        // Method body created by flex in scanner.yy.cpp


    private:
        /* yyval ptr */
        SPL::SPL_Parser::semantic_type *yylval = nullptr;
        /* location ptr */
        SPL::SPL_Parser::location_type *loc = nullptr;
    };

} /* end namespace SPL */

#endif // END __SCANNER_HPP__