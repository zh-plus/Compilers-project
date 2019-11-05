%{
    #include"lex.yy.c"
    void yyerror(char*s){}

    /*
     * We make assumptions on the input:
     * there are no syntax errors, and
     * only consist two operators, plus
     * and minus, and all numbers contain
     * exactly one digit, no spaces.
     */

    // where reverse Polish notation goes
    char *result;
%}
%define api.value.type { char* }
%token TERM ADD SUB

%%
Eval: Expr { result = $1; }
Expr: TERM {
    	$$ = $1;
    	printf("TERM\n");
    }
    | Expr ADD TERM {
    	char str[100];
    	strcpy(str, $1);
    	strcat(str, $3);
    	strcat(str, "+");
    	printf("%s\n", str);
    	printf("Expr ADD TERM\n");
     	$$ = str;
     }
    | Expr SUB TERM {
     	char str[100];
	strcpy(str, $1);
	strcat(str, $3);
	strcat(str, "-");
	printf("%s\n", str);
	printf("Expr SUB TERM\n");
	$$ = str;
     }
%%

char *convert(char *expr){
    YY_BUFFER_STATE buf;
    buf = yy_scan_string(expr);
    yyparse();
    yy_delete_buffer(buf);
    return result;
}

int main(){
    yyin = stdin;
    printf("%s\n", "1");
    yyparse();
    printf("%s\n", result);

    return 0;
}