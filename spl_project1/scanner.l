/* scanner for a toy C-like language */

%{
	#include <string>

	/* Implementation of yyFlexScanner */
	#include "scanner.hpp"
	#undef YY_DECL
	#define YY_DECL int SPL::SPL_Scanner::yylex(SPL::SPL_Parser::semantic_type * const lval, SPL::SPL_Parser::location_type *location)

	/* using "token" to make the returns for the tokens shorter to type */
	using token = SPL::SPL_Parser::token;

	/* define yyterminate as this instead of NULL */
    #define yyterminate() return( token::END )

    /* update location on matching */
    #define YY_USER_ACTION loc->step(); loc->columns(yyleng);

	using namespace std;
%}

%option nodefault
%option yylineno
%option yyclass="SPL::SPL_Scanner"
%option noyywrap
%option c++

DIGIT                   [0-9]

ID                      [a-zA-Z_][0-9a-zA-Z_]*

DECIMAL_INT             ([1-9]{DIGIT}{0,9}|0)
HEX_INT                 0[xX]([1-9A-Fa-f][0-9A-Fa-f]*|0)
DECIMAL_INT_OVERFLOW    {DIGIT}{10}{DIGIT}*

CHAR                    '.'
HEX_CHAR                '\\x[0-9A-Fa-f][0-9A-Fa-f]'

FLOAT                   {DIGIT}+"."{DIGIT}*

LINE_COMMENT            \/\/[^\n\r]*(\n|\r\n|\r)?

%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}

{DECIMAL_INT} {
    //yylval->build<int>(atoi(yytext));
    yylval->build<std::string>(yytext);
    return token::INT;
}

{HEX_INT} {
    //yylval->build<int>((int)strtol(yytext, NULL, 16));
    yylval->build<std::string>(yytext);
    return token::INT;
}

{DECIMAL_INT_OVERFLOW} {
    printf("Error type INT at Line %d: int range overflow(%s is more than 2^32 - 1)\n",
           yylineno, yytext);
}

{CHAR}|{HEX_CHAR} {
	//yylval->build<char>(trim(yytext, "'").c_str()[0]);
	yylval->build<std::string>(yytext);
    return token::CHAR;
}

{FLOAT} {
    //yylval->build<float>(atof(yytext));
    yylval->build<std::string>(yytext);
    return token::FLOAT;
}

int|float|char {        // reserved type
    yylval->build<std::string>(yytext);
    return token::TYPE;
}

"struct" {             // reserved key word
    yylval->build<std::string>(yytext);
    return token::STRUCT;
}

"if" {             // reserved key word
    yylval->build<std::string>(yytext);
    return token::IF;
}

"else" {             // reserved key word
    yylval->build<std::string>(yytext);
    return token::ELSE;
}

"while" {             // reserved key word
    yylval->build<std::string>(yytext);
    return token::WHILE;
}

"return" {             // reserved key word
    yylval->build<std::string>(yytext);
    return token::RETURN;
}

{ID} {
    yylval->build<std::string>(yytext);
    return token::ID;
}

"." {
	yylval->build<std::string>(yytext);
    return token::DOT;
}

";" {
	yylval->build<std::string>(yytext);
	return token::SEMI;
}

"," {
	yylval->build<std::string>(yytext);
	return token::COMMA;
}

"==" {
	yylval->build<std::string>(yytext);
	return token::EQ;
}

"=" {
	yylval->build<std::string>(yytext);
	return token::ASSIGN;
}

"<=" {
	yylval->build<std::string>(yytext);
    return token::LE;
}

"<" {
	yylval->build<std::string>(yytext);
    return token::LT;
}

">=" {
	yylval->build<std::string>(yytext);
    return token::GE;
}

">" {
	yylval->build<std::string>(yytext);
    return token::GT;
}

"!=" {
	yylval->build<std::string>(yytext);
    return token::NE;
}

"!" {
	yylval->build<std::string>(yytext);
    return token::NOT;
}

"+" {
	yylval->build<std::string>(yytext);
	return token::PLUS;
}

"-" {
	yylval->build<std::string>(yytext);
	return token::MINUS;
}

"*" {
	yylval->build<std::string>(yytext);
	return token::MUL;
}

"/" {
	yylval->build<std::string>(yytext);
	return token::DIV;
}

"&&" {
	yylval->build<std::string>(yytext);
	return token::AND;
}

"||" {
	yylval->build<std::string>(yytext);
	return token::OR;
}

"("|")" {
	yylval->build<std::string>(yytext);
	return yytext[0] == '(' ? token::LP : token::RP;
}

"{"|"}" {
    yylval->build<std::string>(yytext);
    return yytext[0] == '{' ? token::LC : token::RC;
}

"["|"]" {
    yylval->build<std::string>(yytext);
    return yytext[0] == '[' ? token::LB : token::RB;
}

{LINE_COMMENT} {
	yylval->build<std::string>(yytext);
    return token::LINE_COMMENT;
}

[ \r\t\n]+ {
    /* Eat up one-line comments */
}

. {
	std::cerr << "Unrecognized character: " << yytext << std::endl;
}

%%