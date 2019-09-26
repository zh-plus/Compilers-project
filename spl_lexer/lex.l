/* scanner for a toy Pascal-like language */

%{
#ifndef LAB_HELPLER_H
#define LAB_HELPLER_H
#include "helpler.h"
#endif //LAB_HELPLER_H

#include <string.h>
//#include <ctype.h>
//#include <stdlib.h>

%}

%option yylineno

DIGIT                   [0-9]

ID                      [a-zA-Z_][0-9a-zA-Z_]*

DECIMAL_INT             ([1-9]{DIGIT}{0,9}|0)
HEX_INT                 0[xX]([1-9A-Fa-f][0-9A-Fa-f]*|0)

DECIMAL_INT_OVERFLOW    {DIGIT}{10}{DIGIT}*

FLOAT                   {DIGIT}+"."{DIGIT}*

KEYWORD                 (struct|if|else|while|return)

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

"("|")" {
    printf("%s\n", strequal(yytext, "(") ? "LP" : "RP");
}

"{"|"}" {
    printf("%s\n", strequal(yytext, "{") ? "LC" : "RC");
}

"=" {
    printf("ASSIGN\n");
}

"," {
    printf("COMMA\n");
}

";" {
    printf("SEMI\n");
}

{ID} {
    printf("ID %s\n", yytext);
}

"+"|"-"|"*"|"/" {
    printf("An operator: %s\n", yytext);
}

"{"[^{}\n]*"}" {
    /* Eat up one-line comments */
}

"//" {
    char c;
    while((c = input()) != '\n');
}

[ \r\t\n]+ {
    /* Eat up one-line comments */
}

. {
//    if (strequal(yytext, "\r"))
//        printf("\\n! === ");
    printf("Unrecognized character: %s\n", yytext);
}

%%

int main(int argc, char **argv){
    ++argv;
    --argc;
    yyin = (argc > 0) ? fopen(argv[0], "r") : stdin;
    yylex();
    printf("Line num: %d\n", yylineno);

    return 0;
}