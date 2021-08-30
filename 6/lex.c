#include "lex.h"

token_t token;
char expr[1000];

void getNextToken(void)
{
    static int i = 0;

    while (expr[i] == '\n' || expr[i] == ' ')
        i++;

    if (expr[i] == '\0')
    {
        token.tokenClass = END;
        return;
    }

    if (expr[i] >= '0' && expr[i] <= '9')
    {
        int x = expr[i] - '0';
        i++;
        while (expr[i] >= '0' && expr[i] <= '9')
        {
            x = x * 10 + expr[i] - '0';
            i++;
        }
        token.tokenClass = NUM;
        token.val = x;
        return;
    }

    if (expr[i] != 'r' && ((expr[i] >= 'a' && expr[i] <= 'z') || (expr[i] >= 'A' && expr[i] <= 'Z')))
    {
        token.tokenClass = ID;
        token.val = expr[i];
        i++;
        return;
    }

    token.tokenClass = expr[i];
    i++;
}

id_struct id_struc[SIZE];

void init_id_struc()
{
    for (int i = 0; i < SIZE; i++)
    {
        id_struc[i].def = 0;
    }
}

int update_id_struc(int index, int val)
{
    id_struc[index].def = 1;
    id_struc[index].val = val;
    return val;
}

int getVal(int index, int *vP)
{
    if (!id_struc[index].def)
        return 0;
    *vP = id_struc[index].val;
    return 1;
}