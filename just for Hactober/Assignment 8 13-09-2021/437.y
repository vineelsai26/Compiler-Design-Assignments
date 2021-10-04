%{
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
    extern int yylineno;
    extern char* symbol_name;

    extern FILE* yyin;
    extern int lineNum;

    struct symbol{
        char name[20];
        int linenumber;
    };

    #define SYMBOL_TABLE_SIZE 9999
    struct symbol symbol_table[SYMBOL_TABLE_SIZE];
    int symbol_table_index = -1;

    void table_lookup(char*, int);
    void add_symbol(char*, int);
    void printTable();

    void add_symbol(char* name, int lineNum){
        for(int i = 0; i <= symbol_table_index; i++){
            if(!strcmp( name, symbol_table[i].name )){
                return;
            }
        }    
            
            symbol_table_index++;
            struct symbol* sym = (struct symbol*) malloc(sizeof(struct symbol));
            strcpy(sym->name, name);
            sym->linenumber = lineNum;
            symbol_table[symbol_table_index] = *sym;
        
    }

    void printTable(){
        if(symbol_table_index == -1)
            return;
        
        for(int i = 0; i <= symbol_table_index; i++){
           continue;
        }
    }

    void table_lookup(char* symbol, int linenumber){
        for(int i = 0; i <= symbol_table_index; i++){
            if(!strcmp( symbol, symbol_table[i].name )){
                return;
            }
        }
    }
%}

%union{
    char* id;
    int integer;
}

%token  IC
%token  FC
%token  IF
%token  THEN
%token  ELSE
%token  WHILE
%token  PRINT
%token  READ
%token  DO
%token  COLON
%token  INT
%token  REAL
%token <id> ID
%token  NOP
%token  EQUAL
%token  SEMICOLON
%token  STR
%token  OR
%token  AND
%token  NOT
%token  LEFT_PARAN
%token  RIGHT_PARAN
%token  DOUBLE_EQUAL
%token  LESS_THAN
%token  GREATER_THAN
%token  ADD
%token  SUB
%token  MUL
%token  DIVIDE

%left AND
%left OR
%left SUB ADD
%left DIVIDE MUL
%left NOT   

%start P
%%

P: DL SL
;

DL: 
    | DL D
;

D: VL COLON TY
;

TY: INT
    | REAL
;

VL: VL ID {add_symbol($2, yylineno);}
    | ID {add_symbol($1, yylineno);}
;

SL: SL S
    | S
;

S:  AS
    | IS
    | LS
    | IOS
    | NOP
;

AS: ID EQUAL E {table_lookup($1, yylineno);}
;

IS: IF BE THEN SL ELSE SL SEMICOLON
;

LS: WHILE BE DO SL SEMICOLON
;

IOS: PRINT PE
    |  READ ID {table_lookup($2, yylineno);}
;


PE: E
    | STR
;

BE: BE OR BE
    | BE AND BE
    | NOT BE
    | LEFT_PARAN BE RIGHT_PARAN
    | RE
;

RE: E DOUBLE_EQUAL E
    | E LESS_THAN E
    | E GREATER_THAN E
;

E:   ID {table_lookup($1, yylineno);}
    | IC
    | FC
    | E ADD E
    | E SUB E
    | E MUL E
    | E DIVIDE E
    | SUB E
    | LEFT_PARAN E RIGHT_PARAN
;

%%
 
int yyerror (char* s){
    printf("%s in line %d\n", s, yylineno);
}

int main(){
    yyin = fopen("sample.txt", "r");
    if(!yyparse()){
        printf("Accepted\n");
    }

    else{
        printf("Rejected\n");
    }
}