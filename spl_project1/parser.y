%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%define api.namespace {SPL}
%define parser_class_name {SPL_Parser}

%code requires{
   namespace SPL {
      class SPL_Driver;
      class SPL_Scanner;
   }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { SPL_Scanner  &scanner  }
%parse-param { SPL_Driver  &driver  }

%code{
    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include <string>

/* include for all driver functions */
#include "spl_driver.hpp"

#undef yylex
#define yylex scanner.yylex

}

%define api.value.type variant
%define parse.assert
%language "C++"

%token               END    0     "end of file"
%token <int>         INT
%token <float>       FLOAT
%token <std::string> TYPE KEYWORD ID
%token <int>         DOT SEMI COMMA
%token <int>         ASSIGN
%token <int>         EQ LE LT GE GT NE
%token <int>         ADD MINUS MUL DIV
%token <int>         AND OR NOT
%token <int>         LP RP LC RC LB RB
%token <std::string> LINE_COMMENT

%locations

%%

list_option : END | list END;

list
  : item
  | list item
  ;

item
  : INT     { driver.scan_int($1); }
  | FLOAT   { driver.scan_float($1); }
  | TYPE    { driver.scan_type($1); }
  | KEYWORD { driver.scan_keyword($1); }
  | ID      { driver.scan_id($1); }
  | DOT     { driver.scan_symbol($1); }
  | SEMI    { driver.scan_symbol($1); }
  | COMMA   { driver.scan_symbol($1); }
  | ASSIGN  { driver.scan_symbol($1); }
  | EQ  { driver.scan_symbol($1); }
  | LE  { driver.scan_symbol($1); }
  | LT  { driver.scan_symbol($1); }
  | GE  { driver.scan_symbol($1); }
  | GT  { driver.scan_symbol($1); }
  | NE  { driver.scan_symbol($1); }
  | ADD    { driver.scan_symbol($1); }
  | MINUS  { driver.scan_symbol($1); }
  | MUL    { driver.scan_symbol($1); }
  | DIV    { driver.scan_symbol($1); }
  | AND    { driver.scan_symbol($1); }
  | OR     { driver.scan_symbol($1); }
  | NOT    { driver.scan_symbol($1); }
  | LP  { driver.scan_symbol($1); }
  | RP  { driver.scan_symbol($1); }
  | LC  { driver.scan_symbol($1); }
  | RC  { driver.scan_symbol($1); }
  | LB  { driver.scan_symbol($1); }
  | RB  { driver.scan_symbol($1); }
  | LINE_COMMENT  { driver.scan_line_comment($1); }
  ;

%%

void SPL::SPL_Parser::error(const location_type &l, const std::string &err_message){
    std::cerr << "Error: " << err_message << " at " << l << std::endl;
}