//
// Created by 10578 on 10/8/2019.
//

#include "splc.h"

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

extern int yyparse();

extern void clear_line_string();

extern int yydebug;

int main(int argc, char **argv) {
    ++argv;
    --argc;
    yyin = fopen(argv[1], "r");
    yyparse();

    return 0;
}