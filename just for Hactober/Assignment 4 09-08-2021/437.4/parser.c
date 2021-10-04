#include"lex.h"
#include "parser.h"
#include<stdio.h>
#include<stdlib.h>

int track[3];

void newNode(ASTnode_t ** a)
{
    *a = (ASTnode_t *)malloc(sizeof(ASTnode_t));
    (*a)->left = NULL;
    (*a)->right = NULL;
    (*a)->val = 0;
    (*a)->op = 'n';
    (*a)->type = '0';
}


int track[3];
int parser(ASTnode_t **a)
{
    if(a != NULL){ 
        getNextToken();
        if(token.tokenClass == '(')
        {
            track[2] += 1;
            (*a)->type = 'I';
            newNode( &((*a)->left) );
            newNode( &((*a)->right) );
            parser( &((*a)->left));
            parser(a);
            parser( &((*a)->right) );
            getNextToken();
            if (token.tokenClass == ')')
            {
                track[2] -= 1;
            }
            if(track[2] == 0){
                return 1;
            }
        }
        else if(token.tokenClass == NUM)
        {
            (*a)->type = 'D';
            (*a)->val = token.val;
            track[0]+=1;
            return 1;
        }
        else if(token.tokenClass == 'r'){
            (*a)->type = 'R';
        }
        if(token.tokenClass == '+' || token.tokenClass == '*')
        {   
            if((*a)->type == 'I'){
                (*a)->op = token.tokenClass;
                track[1]+=1;
            }
            else{
                printf("Some problem with the input\n");
            }
        }
        return 0;
    }
    return 0;
}
