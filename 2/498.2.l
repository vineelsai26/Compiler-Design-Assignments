%{
int a;
%}

%%
[\t ]+    ;

[\n\r]*   {printf("\n");};

"/*".*?"*/"   {printf("<comment>");};

int | 
double | 
float | 
while | 
for | 
if | 
else | 
do {printf("<keyw>");}

,   | 
;    {printf("<delm>");};

"<"   |
">"   |
"=="  |
"<="  |
">="  |
"!="  {printf("<rel-op>");};

=   {printf("<assign-op>");};

"+"    |
"-"    |
"*"    |
"/"    {printf("<arith-op>");};

[+-]?[0-9]+[.]?[0-9]*   {printf("<num>");}; 

[a-zA-z0-9]+   {printf("<id>");}

.   ;
%%

int yywrap(){}
int main() 
{
    extern FILE *yyin;
    yyin = fopen("sample.c", "r");
    yylex();
    return 0;
} 
