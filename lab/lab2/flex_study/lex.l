/* scanner for a toy Pascal-like language */

%{
#include <math.h>
%}

%option yylineno

DIGIT [0-9]
ID    [a-z][a-z0-9]

%%

{DIGIT}+ {
    printf("An integer: %s (%d)\n", yytext, atoi(yytext));
}

{DIGIT}+"."{DIGIT}* {
    printf("A float: %s (%g)\n", yytext, atof(yytext));
}

if|then|begin|end|procedure|function|while {
    printf("A keyword: %s\n", yytext);
}

{ID} {
    printf("An identifier: %s\n", yytext);
}

"+"|"-"|"*"|"/" {
    printf("An operator: %s\n", yytext);
}

"{"[^{}\n]*"}" {
    /* Eat up one-line_no comments */
}

"//" {
    char c;
    while((c = input()) != '\n');
}

[ \t\n]+ {
    /* Eat up one-line_no comments */
}

. {
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