//
// Created by 10578 on 10/9/2019.
//

#include <cctype>
#include <fstream>
#include <cassert>
#include <algorithm>

#include "spl_driver.hpp"


namespace SPL {

    SPL_Driver::~SPL_Driver() {
        delete (scanner);
        scanner = nullptr;
        delete (parser);
        parser = nullptr;
    }

    void SPL_Driver::parse(const char *filename) {
        assert(filename != nullptr);
        std::ifstream in_file(filename);

        if (not in_file.good()) {
            exit(EXIT_FAILURE);
        }

        parse_helper(in_file);
    }

    void SPL_Driver::parse(std::istream &is) {
        if (not is.good()) {
            exit(EXIT_FAILURE);
        } else if (is.eof()) {
            exit(EXIT_SUCCESS);
        }

        parse_helper(is);
    }

    void SPL_Driver::parse_helper(std::istream &is) {
        delete (scanner);
        try {
            scanner = new SPL_Scanner(&is);
        } catch (std::bad_alloc &bad_alloc) {
            std::cerr << "Failed to allocate scanner: (" << bad_alloc.what() << ")!" << std::endl;
            exit(EXIT_FAILURE);
        }

        delete (parser);
        try {
            parser = new SPL_Parser(*scanner, *this);
        } catch (std::bad_alloc &bad_alloc) {
            std::cerr << "Parse Failed!" << std::endl;
            exit(EXIT_FAILURE);
        }

        try {
            parser->parse();
            lexical_errors = scanner->get_errors();
        } catch (const SPL_Parser::syntax_error &e) {
        }
    }

    void SPL_Driver::set_ast(Program_Node *node) {
        ast = new AST(node);
    }

    AST *SPL_Driver::get_ast() {
        return ast;
    }

    SPL_Scanner *SPL_Driver::get_scanner() {
        return scanner;
    }

    bool SPL_Driver::grammar_error_reported() {
        return !syntax_errors->empty() || !lexical_errors->empty();
    }

    bool SPL_Driver::semantic_error_reported(){
        return !semantic_errors->empty();
    }

    std::vector<Error *> *SPL_Driver::get_errors() {
//        std::cout << "lexical errors: " << lexical_errors->size() << std::endl;
//        std::cout << "syntax errors: " << syntax_errors->size() << std::endl;
        if (lexical_errors->empty()) {
            return syntax_errors;
        } else if (syntax_errors->empty()) {
            return lexical_errors;
        }

        auto *all_errors = new std::vector<Error *>(lexical_errors->begin(), lexical_errors->end());

        all_errors->insert(all_errors->end(), syntax_errors->begin(), syntax_errors->end());

        std::sort(all_errors->begin(), all_errors->end(),
                  [](Error *a, Error *b) { return a->info->line_no < b->info->line_no; });

        return all_errors;
    }

    void SPL_Driver::add_syntax_error(std::string lexeme, Scan_Info *info) {
        syntax_errors->push_back(new Syntax_Error(lexeme, info->line_no));
    }

    void SPL_Driver::add_syntax_error(std::string lexeme, AST_Node *info) {
        syntax_errors->push_back(new Syntax_Error(lexeme, info->propagate_line_no()));
    }

    void SPL_Driver::print_errors() {
        for (const auto &error: *get_errors()) {
            std::cout << error->to_string() << std::endl;
        }
    }

    void SPL_Driver::semantic_analyze() {
	    local_resolver.resolve(ast);
    }

//    std::vector<Scan_Info *> make_leaves(std::initializer_list<Scan_Info *> terminal_leaves) {
//        return std::vector<Scan_Info *>(terminal_leaves.begin(), terminal_leaves.end());
//    }
}
