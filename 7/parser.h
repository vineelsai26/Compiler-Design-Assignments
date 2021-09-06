#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    char type;                
    unsigned int val;          
    struct node *left, *right;
    char op;                   
} ASTnode_t;

extern int parser(ASTnode_t **);

#endif