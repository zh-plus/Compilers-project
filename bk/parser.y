%{
    #include <cstdio>
    #include <cstdlib>
    #include "parser.tab.hpp"
    #include "scanner.yy.cpp"

    #ifndef PARSER_TAB_CPP_
    #define PARSER_TAB_CPP_
    #endif

    #define YYSTYPE int

    using namespace std;

    int result;
%}

%language "C++"
%error-verbose
%token INT
%token ADD SUB MUL DIV PERC EQ ABS
%token OP CP

%%
Quiz: Exp EQ { result = $1; }
    ;
Exp: Factor
    | PExp
    | Exp ADD Factor { $$ = $1 + $3; }
    | Exp SUB Factor { $$ = $1 - $3; }
    ;
PExp:
    | Exp ADD Term PERC { $$ = $1 * (1 + $3 / 100.0); }
    | Exp SUB Term PERC { $$ = $1 * (1 - $3 / 100.0); }
Factor: Term
    | Factor MUL Term { $$ = $1 * $3; }
    | Factor DIV Term { $$ = $1 / $3; }
    ;
Term: INT
    | SUB INT { $$ = -$2; }
    | ABS Term ABS { $$ = $2 >= 0 ? $2 : -$2; }
    | OP Exp CP { $$ = $2; }
    ;
%%

void yyerror(const char *s){
    //fflush(stdout);
    printf("*** %s\n", s);
}