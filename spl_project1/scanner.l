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
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::INT;
}

{HEX_INT} {
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::INT;
}

{DECIMAL_INT_OVERFLOW} {
    printf("Error type INT at Line %d: int range overflow(%s is more than 2^32 - 1)\n",
           yylineno, yytext);
}

{CHAR}|{HEX_CHAR} {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::CHAR;
}

{FLOAT} {
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::FLOAT;
}

int|float|char {        // reserved type
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::TYPE;
}

"struct" {             // reserved key word
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::STRUCT;
}

"if" {             // reserved key word
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::IF;
}

"else" {             // reserved key word
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::ELSE;
}

"while" {             // reserved key word
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::WHILE;
}

"return" {             // reserved key word
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::RETURN;
}

{ID} {
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::ID;
}

"." {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::DOT;
}

";" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return token::SEMI;
}

"," {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return token::COMMA;
}

"==" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return token::EQ;
}

"=" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return token::ASSIGN;
}

"<=" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::LE;
}

"<" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::LT;
}

">=" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::GE;
}

">" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::GT;
}

"!=" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::NE;
}

"!" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::NOT;
}

"+" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return token::PLUS;
}

"-" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return token::MINUS;
}

"*" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return token::MUL;
}

"/" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return token::DIV;
}

"&&" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return token::AND;
}

"||" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return token::OR;
}

"("|")" {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
	return yytext[0] == '(' ? token::LP : token::RP;
}

"{"|"}" {
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return yytext[0] == '{' ? token::LC : token::RC;
}

"["|"]" {
    yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return yytext[0] == '[' ? token::LB : token::RB;
}

{LINE_COMMENT} {
	yylval->build<Scan_Info*>(new Scan_Info(std::string(yytext), yylineno));
    return token::LINE_COMMENT;
}

[ \r\t]+ {
    /* Eat up one-line_no comments */
}

\n {
	loc->lines(); // Update line number
}

. {
	yyerror(yytext);
}

%%

void SPL::SPL_Scanner::yyerror (const char *s)
{
	std::cerr << "Error type A at Line " << yylineno << ": unknown lexeme " << s << std::endl;
	exit(EXIT_FAILURE);
}