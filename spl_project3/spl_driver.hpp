//
// Created by 10578 on 10/9/2019.
//

#ifndef ___SPL_DRIVER_HPP__
#define ___SPL_DRIVER_HPP__

#include <string>
#include <cstddef>
#include <istream>
#include <unordered_map>
#include <algorithm>
#include <initializer_list>

#include "ast.hpp"
#include "scanner.hpp"
#include "parser.tab.hpp"
#include "semantics.hpp"
#include "error.hpp"
#include "information.hpp"

namespace SPL {

	class SPL_Driver {
	public:
		SPL_Driver() : parser{nullptr}, scanner{nullptr}, ast{nullptr},
		               syntax_errors{new std::vector<Error *>{}}, semantic_errors{new std::vector<Error *>{}} {};

		virtual ~SPL_Driver();

		/**
		 * Parse from a file.
		 * @param filename - string of input file
		 */
		void parse(const char *filename);

		void parse(std::istream &is);

		void set_ast(SPL::Program_Node *node);

		SPL::AST *get_ast();

		Local_Resolver *get_local_resolver();

		SPL_Scanner *get_scanner();

		std::vector<Error *> *get_grammar_errors();

		std::vector<Error *> *get_semantic_errors();

		void add_syntax_error(std::string lexeme, Scan_Info *info);

		void add_syntax_error(std::string lexeme, AST_Node *node);

		bool grammar_error_reported();

		bool semantic_error_reported();

		void print_errors(std::vector<Error *> *errors);

		void extend_semantic_errors(std::vector<Error *> errors);

		void semantic_analyze();


	private:
		void parse_helper(std::istream &is);

		SPL::SPL_Parser *parser = nullptr;
		SPL::SPL_Scanner *scanner = nullptr;

		SPL::AST *ast = nullptr;

		/* Visitors */
		Local_Resolver *local_resolver = nullptr;

		Dereference_Checker *dereference_checker = nullptr;

		/* Get value after parsing process */
		std::vector<Error *> *lexical_errors = nullptr;

		std::vector<Error *> *syntax_errors;

		std::vector<Error *> *semantic_errors;

		/* define some pretty colors */
		const std::string red = "\033[1;31m";
		const std::string blue = "\033[1;36m";
		const std::string norm = "\033[0m";
	};

	/* Useful functions */

//    std::vector<Scan_Info *> make_leaves(std::initializer_list<Scan_Info *> terminal_leaves);

}

#endif //END ___SPL_DRIVER_HPP__
