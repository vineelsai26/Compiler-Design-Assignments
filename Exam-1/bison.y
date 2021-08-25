%{
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
    #define YYSTYPE int
%}

%token num
%token plus minus mul divi neg power
%token end
%%

line: 
    end
    | expr end {printf("Value of the Expression: %d\n", $1); return 1;}
;

expr: num num plus {$$=$1+$2;}
    | num num minus {$$=$1-$2;}
    | num num mul {$$=$1*$2;}
    | num num divi {$$=$1/$2;}
    | num num power {$$=$1*$2;}
    | num neg {$$=-$1;}
    | num {$$ = $1;}
;

%%

int yyerror(char *s){
    printf("%s\n", s);
}

int main(){
    printf("\nEnter a Expression: ");
    if(yyparse() == 0){
        printf("\nSynatax Error");
    }
}