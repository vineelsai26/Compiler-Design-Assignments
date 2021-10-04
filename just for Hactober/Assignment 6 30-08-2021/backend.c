#include "backend.h"
#include <stdio.h>

bool invalid_expr;

void initParserBackend() {
    invalid_expr = false;
    initSymTab();
}

int compute(ASTnode_t *ptr) {
    if (invalid_expr) 
    {
        return 0;
    }

    if (ptr->type=='D')
    {
        return ptr->val;
    }
    else if (ptr->type=='V') 
    {
        int p;
        if (getVal(ptr->val, &p)) 
            return p;
        else { 
            printf("Value of '%c' is not defined\n", ptr->val);
            invalid_expr = true;
            return 0; 
        }
    }
    else if (ptr->type=='I') {
       
        if (ptr->op == '+')
        {
            return compute(ptr->left) + compute(ptr->right);
        }
        else if(ptr->op == '*')
        {
            return compute(ptr->left) * compute(ptr->right);
        }
        else if (ptr->op == ',')
        {
            compute(ptr->left); 
            return compute(ptr->right);
        }
        else if (ptr->op == '=')
        {
            return updateSymTab(ptr->left->val, compute(ptr->right));
        }
            
        
    }
    else {
        int x;
        printf("r : ");
        scanf("%d", &x);
        return x;
    }
    return 0;
}