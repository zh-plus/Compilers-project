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

%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}

[a-z]       {
               return( token::LOWER );
            }

[A-Z]       {
               return( token::UPPER );
            }

[a-zA-Z]+   {
               /**
                * Section 10.1.5.1 of the 3.0.2 Bison Manual says the
                * following should work:
                * yylval.build( yytext );
                * but it doesn't.
                * ref: http://goo.gl/KLn0w2
                */
               yylval->build< std::string >( yytext );
               return( token::WORD );
            }

\n          {
               /** Update line number **/
               loc->lines();
               return( token::NEWLINE );
            }

.           {
               return( token::CHAR );
            }
%%