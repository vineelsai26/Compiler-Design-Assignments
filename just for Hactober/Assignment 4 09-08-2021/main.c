#include<stdio.h>
#include"lex.h"
#include"parser.h"
#include"backend.h"

int main()
{
    printf("Enter fully paranthesized expression : ");
    ASTnode_t *a;
    if(parser(&a) == 1){
        int ans = evaluate(a);
        printf("The value of the expression is : %d\n" , ans);
    }
    else{
        printf("Please enter the expression with correct sysntax\n");
    }
}