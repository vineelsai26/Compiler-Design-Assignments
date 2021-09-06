#include "backend.h"

void initParserBackend()
{
    initSymTab();
}

int compute(ASTnode_t *node)
{
    if (node->type == 'D')
        return node->val;
    else if (node->type == 'V')
    {
        int p;
        if (getVal(node->val, &p))
            return p;
        else
        {
            printf("Value of '%c' is not defined\n", node->val);
            exit(0);
        }
    }
    else if (node->type == 'I')
    {
        switch (node->op)
        {
        case '+':
            return compute(node->left) + compute(node->right);
        case '*':
            return compute(node->left) * compute(node->right);
        case ',':
            compute(node->left);
            return compute(node->right);
        case '=':
            return updateSymTab(node->left->val, compute(node->right));
        }
    }
    else
    {
        int x;
        printf("Value of r : ");
        scanf("%d", &x);
        return x;
    }
    return 0;
}