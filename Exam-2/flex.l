%{
    #define YYSTYPE int
    #include "bison.tab.h"
    #include <stdlib.h>
    #include <stdio.h>
%}

%option yylineno

whitespace [ \t]
express [A-z0-9=]+
%%

"if" return IF;
"else" return ELSE;
"(" return open_bracket;
")" return close_bracket;
"{" return open_c_bracket;
"}" return close_c_bracket;
";" return semicolon;
"\n" return end;
{whitespace} {}
{express} {
    return EXPR;
}
%%