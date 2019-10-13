%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%define api.namespace {SPL}
%define parser_class_name {SPL_Parser}

%code requires{
   namespace SPL {
      class Scan_Info;

      class SPL_Driver;
      class SPL_Scanner;
      class AST_Node;
      class Leaf_Node;
      class Program_Node;
      class ExtDefList_Node;
      class ExtDef_Node;
      class ExtDecList_Node;
      class Specifier_Node;
      class StructSpecifier_Node;
      class VarDec_Node;
      class FunDec_Node;
      class VarList_Node;
      class ParamDec_Node;
      class CompSt_Node;
      class StmtList_Node;
      class Stmt_Node;
      class DefList_Node;
      class Def_Node;
      class DecList_Node;
      class Dec_Node;
      class Exp_Node;
      class Args_Node;
   }

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
%token <Scan_Info *> INT
%token <Scan_Info *> FLOAT
%token <Scan_Info *> CHAR
%token <Scan_Info *> TYPE ID
%token <Scan_Info *> STRUCT IF ELSE WHILE RETURN
%token <Scan_Info *> ASSIGN
%token <Scan_Info *> DOT SEMI COMMA
%token <Scan_Info *> EQ LE LT GE GT NE
%token <Scan_Info *> PLUS MINUS MUL DIV
%token <Scan_Info *> AND OR NOT
%token <Scan_Info *> LP RP LC RC LB RB
%token <Scan_Info *> LINE_COMMENT
%token 		     ERROR

%type <Program_Node *> Program
%type <ExtDefList_Node *> ExtDefList
%type <ExtDef_Node *> ExtDef
%type <ExtDecList_Node *> ExtDecList
%type <Specifier_Node *> Specifier
%type <StructSpecifier_Node *> StructSpecifier
%type <VarDec_Node *> VarDec
%type <FunDec_Node *> FunDec
%type <VarList_Node *> VarList
%type <ParamDec_Node *> ParamDec
%type <CompSt_Node *> CompSt
%type <StmtList_Node *> StmtList
%type <Stmt_Node *> Stmt
%type <DefList_Node *> DefList
%type <Def_Node *> Def
%type <DecList_Node *> DecList
%type <Dec_Node *> Dec
%type <Exp_Node *> Exp
%type <Args_Node *> Args

%nonassoc ERROR
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
  	//std::cout << "Program -> (ExtDefList)" << std::endl;
  	$$ = new Program_Node($1);
  	driver.set_root($$);
  }
  ;

ExtDefList
  : ExtDef ExtDefList {
  	//std::cout << "ExtDefList - > (ExtDef ExtDefList)" << std::endl;
  	$$ = new ExtDefList_Node($1, $2);
  }
  | %empty {
  	$$ = new Empty_ExtDefList_Node();
  }
  ;

ExtDef
  : Specifier ExtDecList SEMI {
    	//std::cout << "ExtDef - > (Specifier ExtDecList SEMI)" << std::endl;
  	$$ = new ExtDef_Node($1, $2, make_leaf(token::SEMI, $3));
  }
  | Specifier ExtDecList %prec ERROR {
  	driver.add_syntax_error(";", $1);
  }
  | Specifier SEMI {
  	//std::cout << "ExtDef - > (Specifier SEMI)" << std::endl;
  	$$ = new ExtDef_Node($1, make_leaf(token::SEMI, $2));

  }
  | Specifier %prec ERROR {
  	driver.add_syntax_error(";", $1);
  }
  | Specifier FunDec CompSt {
  	//std::cout << "ExtDef - > (Specifier FunDec CompSt)" << std::endl;
  	$$ = new ExtDef_Node($1, $2, $3);
  }
  ;

ExtDecList
  : VarDec {
  	//std::cout << "ExtDecList - > (VarDec)" << std::endl;
  	$$ = new ExtDecList_Node($1);
  }
  | VarDec COMMA ExtDecList {
  	//std::cout << "ExtDecList - > (VarDec COMMA ExtDecList)" << std::endl;
  	$$ = new ExtDecList_Node($1, make_leaf(token::COMMA, $2), $3);
  }
  | VarDec ExtDecList %prec ERROR {
  	driver.add_syntax_error(";", $1);
  }
  ;


/* specifier */
Specifier
  : TYPE {
  	//std::cout << "Specifier - > (TYPE) " << $1->lexeme << std::endl;
  	$$ = new Specifier_Node(make_leaf(token::TYPE, $1));
  }
  | StructSpecifier {
  	//std::cout << "Specifier - > (StructSpecifier)" << std::endl;
  	$$ = new Specifier_Node($1);
  }
  ;

StructSpecifier
  : STRUCT ID LC DefList RC {
  	//std::cout << "StructSpecifier - > (STRUCT ID LC DefList RC)" << std::endl;
  	$$ = new StructSpecifier_Node(make_leaf(token::STRUCT, $1),
  				      make_leaf(token::ID, $2),
  				      make_leaf(token::LC, $3),
  				      $4,
  				      make_leaf(token::RC, $5));
  }
  | STRUCT ID LC DefList %prec ERROR {
  	driver.add_syntax_error("}", $1);
  }
  | STRUCT ID {
  	//std::cout << "StructSpecifier - > (STRUCT ID)" << std::endl;
  	$$ = new StructSpecifier_Node(make_leaf(token::STRUCT, $1),
          			      make_leaf(token::ID, $2));
  }
  ;


/* declarator */
VarDec
  : ID {
  	//std::cout << "VarDec - > (ID) " << $1->lexeme << std::endl;
	$$ = new ID_VarDec_Node(make_leaf(token::ID, $1));
  }
  | VarDec LB INT RB {
  	//std::cout << "VarDec - > (VarDec LB INT RB)" << std::endl;
  	$$ = new Array_VarDec_Node($1,
			     	   make_leaf(token::LB, $2),
			     	   make_leaf(token::INT, $3),
			     	   make_leaf(token::RB, $4));
  }
  | VarDec LB INT %prec ERROR {
  	driver.add_syntax_error("]", $1);
  }
  ;

FunDec
  : ID LP VarList RP {
  	//std::cout << "FunDec - > (ID LP VarList RP) " << $1->lexeme << std::endl;
  	$$ = new FunDec_Node(make_leaf(token::ID, $1),
			     make_leaf(token::LP, $2),
			     $3,
			     make_leaf(token::RP, $4));
  }
  | ID LP VarList %prec ERROR {
    	driver.add_syntax_error(")", $1);
  }
  | ID LP RP {
  	//std::cout << "FunDec - > (ID LP RP) " << $1->lexeme << std::endl;
  	$$ = new FunDec_Node(make_leaf(token::ID, $1),
			     make_leaf(token::LP, $2),
			     make_leaf(token::RP, $3));
  }
  | ID LP %prec ERROR {
    	driver.add_syntax_error(")", $1);
  }
  ;

VarList
  : ParamDec COMMA VarList {
  	//std::cout << "VarList - > (ParamDec COMMA VarList)" << std::endl;
  	$$ = new VarList_Node($1,
			      make_leaf(token::COMMA, $2),
			      $3);
  }
  | ParamDec {
  	//std::cout << "VarList - > (ParamDec)" << std::endl;
  	$$ = new VarList_Node($1);
  }
  ;

ParamDec
  : Specifier VarDec {
  	//std::cout << "ParamDec - > (Specifier VarDec)" << std::endl;
  	$$ = new ParamDec_Node($1, $2);
  }
  ;


/* statement */
CompSt
  : LC DefList StmtList RC {
  	//std::cout << "CompSt - > (LC DefList StmtList RC)" << std::endl;
  	$$ = new CompSt_Node(make_leaf(token::LC, $1),
		             $2,
		             $3,
		             make_leaf(token::RC, $4));
  }
  | LC DefList StmtList %prec ERROR {
  	driver.add_syntax_error("}", {$1});
  }
  ;

StmtList
  : Stmt StmtList {
  	//std::cout << "StmtList - > (Stmt StmtList)" << std::endl;
  	$$ = new StmtList_Node($1, $2);
  }
  | %empty {
  	$$ = new Empty_StmtList_Node();
  }
  ;

Stmt
  : Exp SEMI {
  	//std::cout << "Stmt - > (Exp SEMI)" << std::endl;
  	$$ = new Exp_Stmt_Node($1,
  			       make_leaf(token::SEMI, $2));
  }
//  | Exp %prec ERROR {
//  	driver.add_syntax_error(";", $1);
//  }
  | Exp {
  	driver.add_syntax_error(";", $1);
  }
  | CompSt {
  	//std::cout << "Stmt - > (CompSt)" << std::endl;
  	$$ = new CompSt_Stmt_Node($1);
  }
  | RETURN Exp SEMI {
  	//std::cout << "Stmt - > (RETURN Exp SEMI)" << std::endl;
  	$$ = new Return_Stmt_Node(make_leaf(token::RETURN, $1),
  			   	  $2,
          		   	  make_leaf(token::SEMI, $3));
  }
  | RETURN Exp %prec ERROR {
  	driver.add_syntax_error(";", $1);
  }
  | IF LP Exp RP Stmt {
  	//std::cout << "Stmt - > (IF LP Exp RP Stmt)" << std::endl;
  	$$ = new If_Stmt_Node(make_leaf(token::IF, $1),
  			      make_leaf(token::LP, $2),
  			      $3,
  			      make_leaf(token::RP, $4),
          		      $5);
  }
  | IF LP Exp Stmt %prec ERROR {
	driver.add_syntax_error(")", $1);
  }
  | IF LP Exp RP Stmt ELSE Stmt {
  	//std::cout << "Stmt - > (IF LP Exp RP Stmt ELSE Stmt)" << std::endl;
  	$$ = new If_Stmt_Node(make_leaf(token::IF, $1),
  			      make_leaf(token::LP, $2),
  			      $3,
  			      make_leaf(token::RP, $4),
          		      $5,
          		      make_leaf(token::ELSE, $6),
          		      $7);
  }
  | WHILE LP Exp Stmt ELSE Stmt %prec ERROR {
	driver.add_syntax_error(")", $1);
  }
  | WHILE LP Exp RP Stmt {
  	//std::cout << "Stmt - > (WHILE LP Exp RP Stmt)" << std::endl;
  	$$ = new While_Stmt_Node(make_leaf(token::WHILE, $1),
			         make_leaf(token::LP, $2),
			         $3,
			         make_leaf(token::RP, $4),
			         $5);
  }
  | WHILE LP Exp Stmt %prec ERROR {
	driver.add_syntax_error(")", $1);
  }
  ;


/* local definition */
DefList
  : Def DefList {
  	//std::cout << "DefList - > (Def DefList)" << std::endl;
  	$$ = new DefList_Node($1, $2);
  }
  | %empty {
  	$$ = new Empty_DefList_Node();
  }
  ;

Def
  : Specifier DecList SEMI {
  	//std::cout << "Def - > (Specifier DecList SEMI)" << std::endl;
  	$$ = new Def_Node($1,
  	 		  $2,
  	 		  make_leaf(token::SEMI, $3));
  }
  | Specifier DecList %prec ERROR {
  	driver.add_syntax_error(";", $1);
  }
  ;

DecList
  : Dec {
  	//std::cout << "DecList - > (Dec)" << std::endl;
  	$$ = new DecList_Node($1);
  }
  | Dec COMMA DecList {
  	//std::cout << "DecList - > (Dec COMMA DecList)" << std::endl;
  	$$ = new DecList_Node($1,
  			      make_leaf(token::COMMA, $2),
  			      $3);
  }
  ;

Dec
  : VarDec {
  	//std::cout << "Dec - > (VarDec)" << std::endl;
  	$$ = new Dec_Node($1);
  }
  | VarDec ASSIGN Exp {
  	//std::cout << "Dec - > (VarDec ASSIGN Exp)" << std::endl;
  	$$ = new Dec_Node($1,
  			  make_leaf(token::ASSIGN, $2),
  			  $3);
  }
  ;


/* Expression */
Exp
  : Exp ASSIGN Exp {
  	//std::cout << "Exp - > (Exp ASSIGN Exp)" << std::endl;
  	$$ = new Binary_Exp_Node($1, make_leaf(token::ASSIGN, $2), $3);
  }
  | Exp AND Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::AND, $2), $3);
  }
  | Exp OR Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::OR, $2), $3);
  }
  | Exp LT Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::LT, $2), $3);
  }
  | Exp LE Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::LE, $2), $3);
  }
  | Exp GT Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::GT, $2), $3);
   }
  | Exp GE Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::GE, $2), $3);
  }
  | Exp NE Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::NE, $2), $3);
  }
  | Exp EQ Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::EQ, $2), $3);
  }
  | Exp PLUS Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::PLUS, $2), $3);
  }
  | Exp MINUS Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::MINUS, $2), $3);
  }
  | Exp MUL Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::MUL, $2), $3);
  }
  | Exp DIV Exp {
  	$$ = new Binary_Exp_Node($1, make_leaf(token::DIV, $2), $3);
  }
  | LP Exp RP {
  	$$ = new Parentheses_Exp_Node(make_leaf(token::LP, $1),
  				      $2,
  				      make_leaf(token::RP, $3));
  }
  | LP Exp %prec ERROR {
	driver.add_syntax_error(")", $1);
  }
  | MINUS Exp {
  	$$ = new Unary_Exp_Node(make_leaf(token::MINUS, $1), $2);
  }
  | NOT Exp {
  	$$ = new Unary_Exp_Node(make_leaf(token::NOT, $1), $2);
  }
  | ID LP Args RP {
	$$ = new ID_Parentheses_Exp_Node(make_leaf(token::ID, $1),
				         make_leaf(token::LP, $2),
				         $3,
				         make_leaf(token::RP, $4));
  }
  | ID LP Args %prec ERROR {
	driver.add_syntax_error(")", $1);
  }
  | ID LP RP {
	$$ = new ID_Parentheses_Exp_Node(make_leaf(token::ID, $1),
					 make_leaf(token::LP, $2),
					 make_leaf(token::RP, $3));
  }
  | ID LP %prec ERROR {
	driver.add_syntax_error(")", $1);
  }
  | Exp LB Exp RB {
	$$ = new Bracket_Exp_Node($1,
				  make_leaf(token::LB, $2),
				  $3,
				  make_leaf(token::RB, $4));
  }
  | Exp LB Exp %prec ERROR {
	driver.add_syntax_error("]", $1);
  }
  | Exp DOT ID {
	$$ = new Dot_Exp_Node($1,
			      make_leaf(token::DOT, $2),
			      make_leaf(token::ID, $3));
  }
  | ID {
  	//std::cout << "Exp - > (ID) " << $1->lexeme << std::endl;
  	$$ = new Leaf_Exp_Node(make_leaf(token::ID, $1));
  }
  | INT {
  	//std::cout << "Exp - > (INT) " << $1->lexeme << std::endl;
  	$$ = new Leaf_Exp_Node(make_leaf(token::INT, $1));
  }
  | FLOAT {
  	//std::cout << "Exp - > (FLOAT) " << $1->lexeme << std::endl;
  	$$ = new Leaf_Exp_Node(make_leaf(token::FLOAT, $1));
  }
  | CHAR {
  	//std::cout << "Exp - > (CHAR) " << $1->lexeme << std::endl;
  	$$ = new Leaf_Exp_Node(make_leaf(token::CHAR, $1));
  }
  ;

Args
  : Exp COMMA Args {
  	//std::cout << "Args - > (Exp COMMA Args) " << std::endl;
  	$$ = new Args_Node($1, make_leaf(token::COMMA, $2), $3);
  }
  | Exp {
        //std::cout << "Args - > (Exp) " << std::endl;
        $$ = new Args_Node($1);
  }
  ;

%%

void SPL::SPL_Parser::error(const location_type &l, const std::string &err_message){
    std::cerr << "Auto parser error! " << l.begin << ": unknown lexeme " << err_message << std::endl;
    throw SPL_Parser::syntax_error(l, err_message);
}