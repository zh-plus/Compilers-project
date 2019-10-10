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
      class AST_Node;
      class ASSIGN_Node;
      class ARGS_Node;
      class Leaf_Node;
      class EXP_Node;
      class Binary_EXP_Node;
      class Unary_EXP_Node;
      class Leaf_EXP_Node;
   }

   ///* include for all AST functions */
   //#include "ast.hpp"


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

    /* include for all AST functions */
    #include "ast.hpp"


#undef yylex
#define yylex scanner.yylex

}

%define api.value.type variant
%define parse.assert
%language "C++"
%locations

%token               END    0     "end of file"
%token <std::string> INT
%token <std::string> FLOAT
%token <std::string> CHAR
%token <std::string> TYPE ID
%token <std::string> STRUCT IF ELSE WHILE RETURN
%token <std::string> ASSIGN
%token <std::string> DOT SEMI COMMA
%token <std::string> EQ LE LT GE GT NE
%token <std::string> PLUS MINUS MUL DIV
%token <std::string> AND OR NOT
%token <std::string> LP RP LC RC LB RB
%token <std::string> LINE_COMMENT

%type <EXP_Node *> Exp

%right ASSIGN
%left OR
%left AND
%left LT LE GT GE EQ NE
%left ADD SUB
%left MUL DIV
%right NOT
%left DOT
%left LB RB
%left LP RP

%start Program

%%

/* High-level definition */
Program
  : ExtDefList {
  	std::cout << "Program -> (ExtDefList)" << std::endl;
  }
  ;

ExtDefList
  : ExtDef ExtDefList {
  	std::cout << "ExtDefList - > (ExtDef ExtDefList)" << std::endl;
  }
  | %empty
  ;

ExtDef
  : Specifier ExtDecList SEMI {
  	std::cout << "ExtDef - > (Specifier ExtDecList SEMI)" << std::endl;
  }
  | Specifier SEMI {
  	std::cout << "ExtDef - > (Specifier SEMI)" << std::endl;
  }
  | Specifier FunDec CompSt {
  	std::cout << "ExtDef - > (Specifier FunDec CompSt)" << std::endl;
  }
  ;

ExtDecList
  : VarDec {
  	std::cout << "ExtDecList - > (VarDec)" << std::endl;
  }
  | VarDec COMMA ExtDecList {
  	std::cout << "ExtDecList - > (VarDec COMMA ExtDecList)" << std::endl;
  }
  ;


/* specifier */
Specifier
  : TYPE {
	std::cout << "Specifier - > (TYPE) " << $1 << std::endl;
  }
  | StructSpecifier {
  	std::cout << "Specifier - > (StructSpecifier)" << std::endl;
  }
  ;

StructSpecifier
  : STRUCT ID LC DefList RC {
  	std::cout << "StructSpecifier - > (STRUCT ID LC DefList RC)" << std::endl;
  }
  | STRUCT ID {
  	std::cout << "StructSpecifier - > (STRUCT ID)" << std::endl;
  }
  ;


/* declarator */
VarDec
  : ID {
  	std::cout << "VarDec - > (ID) " << $1 << std::endl;
  }
  | VarDec LB INT RB {
  	std::cout << "VarDec - > (VarDec LB INT RB)" << std::endl;
  }
  ;

FunDec
  : ID LP VarList RP {
  	std::cout << "FunDec - > (ID LP VarList RP) " << $1 << std::endl;
  }
  | ID LP RP {
  	std::cout << "FunDec - > (ID LP RP) " << $1 << std::endl;
  }
  ;

VarList
  : ParamDec COMMA VarList {
  	std::cout << "VarList - > (ParamDec COMMA VarList)" << std::endl;
  }
  | ParamDec {
  	std::cout << "VarList - > (ParamDec)" << std::endl;
  }
  ;

ParamDec
  : Specifier VarDec {
  	std::cout << "ParamDec - > (Specifier VarDec)" << std::endl;
  }
  ;


/* statement */
CompSt
  : LC DefList StmtList RC {
  	std::cout << "CompSt - > (LC DefList StmtList RC)" << std::endl;
  }
  ;

StmtList
  : Stmt StmtList {
  	std::cout << "StmtList - > (Stmt StmtList)" << std::endl;
  }
  | %empty
  ;

Stmt
  : Exp SEMI {
  	std::cout << "Stmt - > (Exp SEMI)" << std::endl;
  }
  | CompSt {
  	std::cout << "Stmt - > (CompSt)" << std::endl;
  }
  | RETURN Exp SEMI {
  	std::cout << "Stmt - > (RETURN Exp SEMI)" << std::endl;
  }
  | IF LP Exp RP Stmt {
  	std::cout << "Stmt - > (IF LP Exp RP Stmt)" << std::endl;
  }
  | IF LP Exp RP Stmt ELSE Stmt {
  	std::cout << "Stmt - > (IF LP Exp RP Stmt ELSE Stmt)" << std::endl;
  }
  | WHILE LP Exp RP Stmt {
  	std::cout << "Stmt - > (WHILE LP Exp RP Stmt)" << std::endl;
  }
  ;


/* local definition */
DefList
  : Def DefList {
  	std::cout << "DefList - > (Def DefList)" << std::endl;
  }
  | %empty
  ;

Def
  : Specifier DecList SEMI {
  	std::cout << "Def - > (Specifier DecList SEMI)" << std::endl;
  }
  ;

DecList
  : Dec {
  	std::cout << "DecList - > (Dec)" << std::endl;
  }
  | Dec COMMA DecList {
  	std::cout << "DecList - > (Dec COMMA DecList)" << std::endl;
  }
  ;

Dec
  : VarDec {
  	std::cout << "Dec - > (VarDec)" << std::endl;
  }
  | VarDec ASSIGN Exp {
  	std::cout << "Dec - > (VarDec ASSIGN Exp)" << std::endl;
  }
  ;


/* Expression */
Exp
  : Exp ASSIGN Exp {
  	std::cout << "Exp - > (Exp ASSIGN Exp)" << std::endl;
  	$$ = new Binary_EXP_Node(token::ASSIGN, $1, $3);
  	driver.set_root($$);
  }
  | Exp AND Exp {
  	$$ = new Binary_EXP_Node(token::AND, $1, $3);
  }
  | Exp OR Exp {
  	$$ = new Binary_EXP_Node(token::OR, $1, $3);
  }
  | Exp LT Exp {
  	$$ = new Binary_EXP_Node(token::LT, $1, $3);
  }
  | Exp LE Exp {
  	$$ = new Binary_EXP_Node(token::LE, $1, $3);
  }
  | Exp GT Exp {
  	$$ = new Binary_EXP_Node(token::GT, $1, $3);
   }
  | Exp GE Exp {
  	$$ = new Binary_EXP_Node(token::GE, $1, $3);
  }
  | Exp NE Exp {
  	$$ = new Binary_EXP_Node(token::NE, $1, $3);
  }
  | Exp EQ Exp {
  	$$ = new Binary_EXP_Node(token::EQ, $1, $3);
  }
  | Exp PLUS Exp {
  	$$ = new Binary_EXP_Node(token::PLUS, $1, $3);
  }
  | Exp MINUS Exp {
  	$$ = new Binary_EXP_Node(token::MINUS, $1, $3);
  }
  | Exp MUL Exp {
  	$$ = new Binary_EXP_Node(token::MUL, $1, $3);
  }
  | Exp DIV Exp {
  	$$ = new Binary_EXP_Node(token::DIV, $1, $3);
  }
  | LP Exp RP {
  	$$ = $2;
  }
  | MINUS Exp {
  	$$ = new Unary_EXP_Node(token::MINUS, $1);
  }
  | NOT Exp {
  	$$ = new Unary_EXP_Node(token::NOT, $1);
  }
  | ID LP Args RP {
  	$$ = new Unary_EXP_Node(token::ID, "testing ID LP Args RP");
  }
  | ID LP RP {
  	std::cout << "Exp - > (ID LP RP) " << $1 << std::endl;
  	$$ = new Unary_EXP_Node(token::ID, "testing ID LP Args RP");
  }
  | Exp LB Exp LB {
  	$$ = new Unary_EXP_Node(token::ID, "testing Exp LB Exp LB");
  }
  | Exp DOT ID {
  	$$ = new Unary_EXP_Node(token::ID, "testing Exp DOT ID");
  }
  | ID {
  	std::cout << "Exp - > (ID) " << $1 << std::endl;
  	$$ = new Leaf_EXP_Node(token::ID, $1);
  }
  | INT {
  	std::cout << "Exp - > (INT) " << $1 << std::endl;
  	$$ = new Leaf_EXP_Node(token::INT, $1);
  }
  | FLOAT {
  	std::cout << "Exp - > (FLOAT) " << $1 << std::endl;
  	$$ = new Leaf_EXP_Node(token::FLOAT, $1);
  }
  | CHAR {
  	std::cout << "Exp - > (CHAR) " << $1 << std::endl;
  	$$ = new Leaf_EXP_Node(token::CHAR, $1);
  }
  ;

Args
  : Exp COMMA Args {
  	std::cout << "Args - > (Exp COMMA Args) " << std::endl;
  }
  | Exp {
        std::cout << "Args - > (Exp) " << std::endl;
  }
  ;

%%

void SPL::SPL_Parser::error(const location_type &l, const std::string &err_message){
    std::cerr << "Error: " << err_message << " at " << l << std::endl;
}