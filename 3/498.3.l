%{

%}

%%
[\t ]+    ;

[\n\r]*   {fprintf(yyout, "\n");};

"/*".*?"*/"   {fprintf(yyout, "<comment>");};

int | 
double | 
float |
char |
long |
void {fprintf(yyout, "<keyw_datatype>");};
 
while   | 
for     | 
if      | 
else    | 
do {fprintf(yyout, "<keyw_%s>", yytext);}

"("   |    
")"   |
"{"   |
"}"   |
,     | 
;    {fprintf(yyout, "<delm%s>", yytext);};

"<"   |
">"   |
"=="  |
"<="  |
">="  |
"!="  {fprintf(yyout, "<rel-op>");};

=   {fprintf(yyout, "<op_assign>");};

"++"   |
--   {fprintf(yyout, "<op_incdec>");};

"+"    |
"-"    |
"*"    |
"/"    {fprintf(yyout, "<arith-op>");};

[+-]?[0-9]+[.]?[0-9]*   {fprintf(yyout, "<id-%s>", yytext);}; 

[a-zA-z0-9]+   {fprintf(yyout, "<id-%s>", yytext);}

.   ;
%%

int yywrap(){}
int main() 
{
    extern FILE *yyin, *yyout;
    yyin = fopen("sample.c", "r");
    yyout=fopen("output.txt","w");
    yylex();
    return 0;
}
