/* scanner for a toy Pascal-like language */

%{
	#include <iostream>
	#include <cstdio>
	#include <cstdlib>
	#include "helpler.h"
	#include "parser.tab.hpp"

	using namespace std;
%}

%option yylineno
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

{DECIMAL_INT} {
    printf("INT %d\n", atoi(yytext));
}

{HEX_INT} {
    printf("INT %d\n", (int)strtol(yytext, NULL, 16));
}

{DECIMAL_INT_OVERFLOW} {
    printf("Error type INT at Line %d: int range overflow(%s is more than 2^32 - 1)\n",
           yylineno, yytext);
}

{FLOAT} {
    printf("FLOAT %g\n", atof(yytext));
}

int|float|char {        // reserved type
    printf("TYPE %s\n", yytext);
}

{KEYWORD} {             // reserved key word
    printf("%s\n", strupr(yytext));
}

{ID} {
    printf("ID %s\n", yytext);
}

"." {
    printf("DOT\n");
}

";" {
    printf("SEMI\n");
}

"," {
    printf("COMMA\n");
}

"==" {
    printf("EQ\n");
}

"=" {
    printf("ASSIGN\n");
}

"<=" {
    printf("LE\n");
}

"<" {
    printf("LT\n");
}

">=" {
    printf("GE\n");
}

">" {
    printf("GT\n");
}

"!=" {
    printf("NE\n");
}

"!" {
    printf("NOT\n");
}

"+" {
    printf("ADD\n");
}

"-" {
    printf("MINUS\n");
}

"*" {
    printf("MUL\n");
}

"/" {
    printf("DIV\n");
}

"&&" {
    printf("AND\n");
}

"||" {
    printf("OR\n");
}

"("|")" {
    printf("%s\n", yytext[0] == '(' ? "LP" : "RP");
}

"{"|"}" {
    printf("%s\n", yytext[0] == '{' ? "LC" : "RC");
}

"["|"]" {
    printf("%s\n", yytext[0] == '[' ? "LB" : "RB");
}

{LINE_COMMENT} {
    printf("line comment: %s", &yytext[2]);
}

[ \r\t\n]+ {
    /* Eat up one-line comments */
}

. {
    printf("Unrecognized character: %s\n", yytext);
}

%%