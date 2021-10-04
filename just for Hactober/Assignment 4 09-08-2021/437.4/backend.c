#include<stdio.h>
#include"backend.h"

int ans;


int evaluate(ASTnode_t * ptr){
    if(ptr != NULL){
        int temp1 = evaluate(ptr->left);
        int temp2 = evaluate(ptr->right);

        if(ptr->type == 'D'){
            return ptr->val;
        }
        else if(ptr->type == 'R'){
            int temp;
            printf("Enter value of r: ");
            scanf("%d" , &temp);
            return temp;
        }
        else if(ptr->type == 'I'){
            if(ptr->op == '+')
                return temp1+temp2;
            else
                return temp1*temp2;
        }
        
    }
    return 0;
}