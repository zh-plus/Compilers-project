//
// Created by 10578 on 10/9/2019.
//

#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__

#if !defined(yyFlexLexerOnce)

#include <FlexLexer.h>

#endif

#include <unordered_map>
#include "parser.tab.hpp"
#include "location.hh"
#include "error.hpp"
#include "information.hpp"

namespace SPL {

	class SPL_Scanner : public yyFlexLexer {
	public:

		SPL_Scanner(std::istream *in) : yyFlexLexer(in), loc{new SPL::SPL_Parser::location_type()},
		                                lexical_errors{new std::vector<Error *>{}} {
		};

		//get rid of override virtual function warning
		using FlexLexer::yylex;

		virtual int yylex(SPL::SPL_Parser::semantic_type *const lval,
		                  SPL::SPL_Parser::location_type *location);
		// YY_DECL defined in scanner.l
		// Method body created by flex in scanner.yy.cpp

		void add_error(Scan_Info *info) {
			lexical_errors->push_back(new Lexical_Error(info));
		};

		bool error_reported() {
			return !lexical_errors->empty();
		}

		std::vector<Error *> *get_errors() {
			return lexical_errors;
		}

	private:
		/* yyval ptr */
		SPL::SPL_Parser::semantic_type *yylval = nullptr;
		/* location ptr */
		SPL::SPL_Parser::location_type *loc = nullptr;

		std::vector<Error *> *lexical_errors = nullptr;
	};

} /* end namespace SPL */

#endif // END __SCANNER_HPP__