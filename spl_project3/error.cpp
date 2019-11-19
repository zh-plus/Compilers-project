//
// Created by 10578 on 2019/11/16.
//

#include "scanner.hpp"
#include "error.hpp"
#include "information.hpp"


bool SPL::Error::operator<(const SPL::Error &obj) {
    return line_no < obj.line_no;
}

std::string SPL::Lexical_Error::to_string() {
    return "Error type A at Line " + std::to_string(info->line_no) + ": unknown lexeme " + info->lexeme;
}

SPL::Lexical_Error::Lexical_Error(Scan_Info *info) {
    this->info = info;
    this->line_no = info->line_no;
}

SPL::Syntax_Error::Syntax_Error(std::string lexeme, int line_no) {
    this->info = new Scan_Info(lexeme, line_no);
}

std::string SPL::Syntax_Error::to_string() {
    return "Error type B at Line " + std::to_string(info->line_no) +
           ": Missing " + punctuation_map[info->lexeme] + " " + info->lexeme;
}

SPL::Syntax_Error::Syntax_Error(Scan_Info *info) {
    this->info = info;
    this->line_no = info->line_no;
}

std::string SPL::Semantic_Error::to_string() {
    return "Error type " + std::to_string(error_type) + " at Line " + std::to_string(line_no) + ": " + get_message();
}

std::string SPL::Semantic_Error1::get_message() {
    return "Variable " + variable_id + " is used without definition";
}

std::string SPL::Semantic_Error2::get_message() {
    return "Function " + func_id + " is invoked without definition";
}

std::string SPL::Semantic_Error3::get_message() {
    return "Variable " + variable_id + " have been defined at line " + std::to_string(defined_line);
}

std::string SPL::Semantic_Error4::get_message() {
    return "Function " + func_id + " have been defined at line " + std::to_string(defined_line);
}

std::string SPL::Semantic_Error5::get_message() {
    return "Unmatching types on both sides of assignment operator (=)";
}

std::string SPL::Semantic_Error6::get_message() {
    return "Rvalue on the left side of assignment operator";
}

std::string SPL::Semantic_Error7::get_message() {
    return "Unmatching operands, such as adding an integer to a structure variable";
}

std::string SPL::Semantic_Error8::get_message() {
    return "The function's return value type mismatches the declared type";
}

std::string SPL::Semantic_Error9::get_message() {
    return "The function's arguments mismatch the declared parameters (types or numbers, or both)";
}

std::string SPL::Semantic_Error10::get_message() {
    return "Applying indexing operator on non-array type variables";
}

std::string SPL::Semantic_Error11::get_message() {
    return "Applying function invocation operator on non-function names";
}

std::string SPL::Semantic_Error12::get_message() {
    return "Array indexing with non-integer type expression";
}

std::string SPL::Semantic_Error13::get_message() {
    return "Accessing member of non-structure variable";
}

std::string SPL::Semantic_Error14::get_message() {
    return "Accessing an undefined structure member";
}

std::string SPL::Semantic_Error15::get_message() {
    return "Structure: " + struct_id + " have been defined at line " + std::to_string(defined_line);
}

std::string SPL::Semantic_Error16::get_message() {
    return "Structure: " + struct_id + " is not defined";
}

std::string SPL::Semantic_Error17::get_message() {
    return "Structure: " + struct_id + " is defined incompletely(without member definition)";
}
