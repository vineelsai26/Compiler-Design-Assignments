#ifndef PARSER_H
#define PARSER_H

typedef struct node {
    char type;                  
    unsigned int val;           
    struct node *left, *right;  
    char op;                    
} ASTnode_t;

extern int parser(ASTnode_t **);

#endif