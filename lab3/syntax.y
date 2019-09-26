%{
    #include"lex.yy.c"
    void yyerror(const char*);
    int result;
%}
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
//    | Term PERC {
//    	$$ = $1 / 100.0;
//    	printf("%f\n", (double)($1 / 100.0));
//    }
    ;
%%
void yyerror(const char *s){
    fprintf(stderr, "%s\n", s);
}
#ifndef CALC_MAIN
#else
int main(){
    yyparse();
    printf(" = %d\n", result);
}
#endif


double evaluate(char *expr){
    YY_BUFFER_STATE buf;
    buf = yy_scan_string(expr);
    yyparse();
    yy_delete_buffer(buf);
    return result;
}

