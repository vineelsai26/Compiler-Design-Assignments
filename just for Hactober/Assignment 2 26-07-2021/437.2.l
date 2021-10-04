%{
    #include<stdio.h>
%}

%%
    /*=========Rules=========*/    
[\n\t]+      ;      /*Ignoring Spaces*/
\/\/(.*)    {};    /*ignore single line comments*/   
\/\*(.*\n)*.*\*\/  {};      /*ignore multi line comment*/
int|double|for|while|if|then|else|do|float      {printf("<keyw>");}    /*Keywords*/
[a-zA-z]([a-z]|[A-Z]|[_]|[0-9])*    {printf("<id>");}    /*identifiers*/
[;{}]     {printf("<delim>\n");}     /*Deliminator*/
[,]     {printf("<delim>");}        /*Deliminator*/
[=]     {printf("<assign_op>");}    /*assignment operator*/
[+-/*]      {printf("<arith_op>");}    /*Arithmatic Operators*/
[<>]      {printf("<rel_op>");}    /*Relational operators*/
<=|>=|!=    {printf("<rel_op>");}    /*Relational operators*/
[0-9]*[.]?[0-9]*    {printf("<num>");}    /*Numbers*/

%%

int yywrap(){}

int main(void)
{
    extern FILE *yyin, *yyout;
    yyin = fopen("sample.c", "r");
    
    yylex();
    return 0;
}