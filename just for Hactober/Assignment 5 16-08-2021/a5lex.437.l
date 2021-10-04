%{
    #define YYSTYPE int
    #include "a5parse.437.tab.h"
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

"r" {
    printf("Enter a value for r :  ");
    int r;
    scanf("%d", &r);
    yylval = r;
    return var;
}
"+" return plus;
"*" return into;
"(" return lp;
")" return rp;
"\n" return end;
%%