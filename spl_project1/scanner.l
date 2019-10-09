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

FLOAT                   {DIGIT}+"."{DIGIT}*

KEYWORD                 (struct|if|else|while|return)

LINE_COMMENT            \/\/[^\n\r]*(\n|\r\n|\r)?

%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}

{DECIMAL_INT} {
    yylval->build<int>(atoi(yytext));
    return token::INT;
}

{HEX_INT} {
    yylval->build<int>((int)strtol(yytext, NULL, 16));
    return token::INT;
}

{DECIMAL_INT_OVERFLOW} {
    printf("Error type INT at Line %d: int range overflow(%s is more than 2^32 - 1)\n",
           yylineno, yytext);
}

{FLOAT} {
    yylval->build<float>(atof(yytext));
    return token::FLOAT;
}

int|float|char {        // reserved type
    yylval->build<std::string>(yytext);
    return token::TYPE;
}

{KEYWORD} {             // reserved key word
    yylval->build<std::string>(yytext);
    return token::KEYWORD;
}

{ID} {
    yylval->build<std::string>(yytext);
    return token::ID;
}

"." {
	yylval->build<int>(token::DOT);
    return token::DOT;
}

";" {
	yylval->build<int>(token::SEMI);
	return token::SEMI;
}

"," {
	yylval->build<int>(token::COMMA);
	return token::COMMA;
}

"==" {
	yylval->build<int>(token::EQ);
	return token::EQ;
}

"=" {
	yylval->build<int>(token::ASSIGN);
	return token::ASSIGN;
}

"<=" {
	yylval->build<int>(token::LE);
    return token::LE;
}

"<" {
	yylval->build<int>(token::LT);
    return token::LT;
}

">=" {
	yylval->build<int>(token::GE);
    return token::GE;
}

">" {
	yylval->build<int>(token::GT);
    return token::GT;
}

"!=" {
	yylval->build<int>(token::NE);
    return token::NE;
}

"!" {
	yylval->build<int>(token::NOT);
    return token::NOT;
}

"+" {
	yylval->build<int>(token::ADD);
	return token::ADD;
}

"-" {
	yylval->build<int>(token::MINUS);
	return token::MINUS;
}

"*" {
	yylval->build<int>(token::MUL);
	return token::MUL;
}

"/" {
	yylval->build<int>(token::DIV);
	return token::DIV;
}

"&&" {
	yylval->build<int>(token::AND);
	return token::AND;
}

"||" {
	yylval->build<int>(token::OR);
	return token::OR;
}

"("|")" {
	int _token = yytext[0] == '(' ? token::LP : token::RP;
	yylval->build<int>(_token);
	return _token;
}

"{"|"}" {
	int _token = yytext[0] == '{' ? token::LC : token::RC;
    yylval->build<int>(_token);
    return _token;
}

"["|"]" {
	int _token = yytext[0] == '[' ? token::LB : token::RB;
    yylval->build<int>(_token);
    return _token;
}

{LINE_COMMENT} {
	yylval->build<std::string>(&yytext[2]);
    return token::LINE_COMMENT;
}

[ \r\t\n]+ {
    /* Eat up one-line comments */
}

. {
	std::cerr << "Unrecognized character: " << yytext << std::endl;
}

%%