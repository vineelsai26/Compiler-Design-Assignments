%{
    #define YYSTYPE int
    #include "bison.tab.h"
    #include <stdlib.h>
    #include <stdio.h>
%}

whitespace [ \t]
integer [0-9]+

%%

{whitespace} {}
{integer} {
    yylval = atof(yytext);
    return num;
}
"+" return plus;
"-" return minus;
"*" return mul;
"/" return divi;
"n" return neg;
"^" return power;
"\n" return end;
%%