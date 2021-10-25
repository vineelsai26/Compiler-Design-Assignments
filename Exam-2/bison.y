%{
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
    #define YYSTYPE int
    extern int yylineno;
%}

%locations

%token IF ELSE EXPR
%token open_bracket close_bracket open_c_bracket close_c_bracket semicolon
%token end
%%

line: expr end
    | expr expr end
    | expr end expr end
    | expr 
;

expr: IF open_bracket EXPR close_bracket
    | open_c_bracket EXPR semicolon close_c_bracket
    | IF open_bracket EXPR close_bracket open_c_bracket EXPR semicolon close_c_bracket ELSE open_c_bracket EXPR semicolon close_c_bracket
    | IF open_bracket EXPR close_bracket open_c_bracket EXPR semicolon close_c_bracket
    | ELSE
    | ELSE open_c_bracket EXPR semicolon close_c_bracket
    | IF open_bracket EXPR close_bracket open_c_bracket EXPR semicolon close_c_bracket ELSE open_c_bracket EXPR semicolon close_c_bracket EXPR
    | IF open_bracket EXPR close_bracket open_c_bracket EXPR semicolon close_c_bracket EXPR
    | ELSE open_c_bracket EXPR semicolon close_c_bracket EXPR
;

%%

int yyerror(char *s){
    printf("Error | Line: %d \t %s\n",yylineno,s);
}

int main(){
    printf("Enter a Expression: ");
    if(yyparse() == 0){
        
    }
}
