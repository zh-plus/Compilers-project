#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int a = 10;
    int b = 1000000000000;
    int yylineno = 10;
    char *yytext = "123123123";


    char *num = "0xA";
    printf("%ld", strtol(num, NULL, 16));

    return 0;
}