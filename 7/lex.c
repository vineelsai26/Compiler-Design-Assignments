#include "lex.h"
#include "symTab.h"

token_t token;
char expr[1000];

void getNextToken(void)
{
    static int i = 0;

    while (expr[i] == '\n' || expr[i] == ' ')
    {
        i++;
    }

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