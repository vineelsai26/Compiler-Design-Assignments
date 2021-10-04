%{
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
    #define YYSTYPE int
%}


%token num
%token plus into
%token lp rp
%token end
%token var

%left plus
%left into


%%

line: 
    end
    | expr end {printf("Value of the Expression: %d\n", $1); return 1;}
;

expr: lp expr rp {$$=$2;}
    | num {$$ = $1;}
    | expr plus expr { $$ = $1 + $3; }
    | expr into expr { $$ = $1 * $3; }
    | var {$$ = $1;}

;

%%

int yyerror(char *s){
    printf("%s\n", s);
}

int main(){

    printf("\nEnter a fully paranthesised expression: ");

    if(yyparse() == 0){
        printf("\nSynatax Error");
    }

    else{
       printf("Parsed Successfully !!!\n");
    }
}