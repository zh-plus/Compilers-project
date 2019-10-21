%{
    #include"lex.yy.c"
    void yyerror(const char*);
    int result;

    /*
     *  This code can only solve the #iphone# case.
     *  Another two cases requires more advanced Bison features.
     *  They will be covered in the later lab session.
     */
%}
%error-verbose
%token INT
%token ADD SUB MUL DIV PERC EQ
%%
Quiz: Exp EQ { result = $1; }
    ;
Exp: Factor
    | DExp
    | Exp ADD Factor { $$ = $1 + $3; }
    | Exp SUB Factor { $$ = $1 - $3; }
    ;
DExp:
      Exp ADD INT PERC { $$ = $1 * (1 + 0.01*$3); }
    | Exp SUB INT PERC { $$ = $1 * (1 - 0.01*$3); }
    ;
Factor: INT
    | Factor MUL INT { $$ = $1 * $3; }
    | Factor DIV INT { $$ = $1 / $3; }
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


int evaluate(char *expr){
    YY_BUFFER_STATE buf;
    buf = yy_scan_string(expr);
    yyparse();
    yy_delete_buffer(buf);
    return result;
}
