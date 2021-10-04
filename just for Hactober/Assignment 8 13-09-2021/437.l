%{
    #include "437.tab.h"
    #include <stdlib.h>
    #include <stdio.h>
    int lineNum = 0;
    char* symbol_name;

%}

%option yylineno
%option noyywrap
white [ \t]+
digit [0-9]
integer {digit}+
exponent [eE][+-]?{integer}
real {integer}("."{integer})?{exponent}?
 
%%

"//".*\n {}
[ \t\n] {}
{white} {}
{integer} {
    return IC;
}
{real} {
    return FC;
}

"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"while" {return WHILE;}
"print" {return PRINT;}
"read" {return READ;}
"do" {return DO;}
"int" {return INT;}
"real" {return REAL;}
"float" {return REAL;}
"nop" {return NOP;}
[a-zA-Z][a-zA-Z0-9]* { 
                        yylval.id = (char *) strdup(yytext);
                        return ID;}
":" {return COLON;}
";" {return SEMICOLON;}
"=" {return EQUAL;}
"|" {return OR;}
"~" {return NOT;}
"(" {return LEFT_PARAN;}
")" {return RIGHT_PARAN;}
"==" {return DOUBLE_EQUAL;}
"<" {return LESS_THAN;}
">" {return GREATER_THAN;}
"&" {return AND;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIVIDE;}

"\""[a-zA-Z]*"\"" {return STR;}
%%