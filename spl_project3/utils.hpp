//
// Created by 10578 on 10/10/2019.
//

#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <algorithm>
#include <functional>
#include <locale>
#include <string>
#include <sstream>
#include <unordered_map>
#include "parser.tab.hpp"

namespace SPL {
	class SPL_Parser;

	using token = SPL_Parser::token;

	static std::unordered_map<int, std::string> symbol_map{
			{token::INT,   "INT"},
			{token::FLOAT, "FLOAT"},
			{token::CHAR,   "CHAR"},
			{token::ID,     "ID"},
			{token::TYPE,   "TYPE"},
			{token::STRUCT, "STRUCT"},
			{token::IF,     "IF"},
			{token::ELSE,   "ELSE"},
			{token::WHILE,  "WHILE"},
			{token::RETURN, "RETURN"},
			{token::DOT,    "DOT"},
			{token::SEMI,   "SEMI"},
			{token::COMMA,  "COMMA"},
			{token::ASSIGN, "ASSIGN"},
			{token::LE,     "LE"},
			{token::LT,     "LT"},
			{token::GE,     "GT"},
			{token::GT,    "GT"},
			{token::NE,    "NE"},
			{token::EQ,    "EQ"},
			{token::PLUS,  "PLUS"},
			{token::MINUS, "MINUS"},
			{token::MUL,   "MUL"},
			{token::DIV,   "DIV"},
			{token::AND,   "AND"},
			{token::OR,    "OR"},
			{token::NOT,   "NOT"},
			{token::LP,    "LP"},
			{token::RP,    "RP"},
			{token::LB,    "LB"},
			{token::RB,    "RB"},
			{token::LC,    "LC"},
			{token::RC,    "RC"}
	};

	std::string trim(const std::string &str, const std::string &ws);

	/**
	 * Join the elements by separator into a string.
	 * @tparam Iter
	 * @param begin
	 * @param end
	 * @param separator
	 * @return
	 */
	template<typename Iter>
	std::string join(Iter begin, Iter end, std::string const &separator) {
		std::ostringstream result;
		if (begin != end) {
			result << *begin++;
		}

		while (begin != end) {
			result << separator << *begin++;
		}

		return result.str();
	}

	template<typename T>
	std::string join(std::initializer_list<T> seq, std::string const &separator) {
		return join(begin(seq), end(seq), separator);
	}
}

#endif //COMPILERS_UTIL_HPP
