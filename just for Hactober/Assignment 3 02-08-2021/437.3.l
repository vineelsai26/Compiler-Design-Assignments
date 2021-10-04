%{
    #include<stdio.h>
%}

%%
    /*=========Rules=========*/    
[\n\t]+      ;      /*Ignoring Spaces*/
int|double|char|float      {fprintf(yyout,"<keyw_datatype-%s>",yytext);}    /*Keywords*/
[a-zA-z]([a-z]|[A-Z]|[_]|[0-9])*    {fprintf(yyout,"<id>");}    /*identifiers*/
[;{}]     {fprintf(yyout,"<delim-%s>\n",yytext);}     /*Deliminator*/
[,]     {fprintf(yyout,"<delim-%s>",yytext);}        /*Deliminator*/
[=]     {fprintf(yyout,"<assign_op-%s>",yytext);}    /*assignment operator*/
[+-/*]      {fprintf(yyout,"<arith_op-%s>",yytext);}    /*Arithmatic Operators*/
[<>]      {fprintf(yyout,"<rel_op-%s>",yytext);}    /*Relational operators*/
[<=]|[>=]|[!=]    {fprintf(yyout,"<rel_op-%s>",yytext);}    /*Relational operators*/
[0-9]*[.]?[0-9]*    {fprintf(yyout,"<num>");}    /*Numbers*/

%%

int yywrap(){}

int main(void)
{
    extern FILE *yyin, *yyout;
    yyin = fopen("sample.c", "r");

    yyout = fopen("Output.txt", "w");
    
    yylex();
    return 0;
}