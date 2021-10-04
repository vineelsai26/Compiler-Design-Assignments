#include "lex.h"

token_t token;
char expr[1000];

void getNextToken(void) {
    static int i = 0;
    
    while (expr[i]=='\n' || expr[i]==' ')
        i++;

    if (expr[i]=='\0') {
        token.tokenClass = END;
        return;
    }

    if (expr[i]>= 48 && expr[i]<=57) {
        int x = expr[i] - 48;
        i++;
        while(expr[i]>= 48 && expr[i]<=57) {
            x = x*10 + expr[i] - 48;
            i++;
        }
        token.tokenClass = NUM;
        token.val = x;
        return;
    }

    if (expr[i]!=114 && (expr[i]>=97 && expr[i]<=112))
    {
        token.tokenClass = ID;
        token.val = expr[i];
        i++;
        return;
    }

    token.tokenClass = expr[i];
    i++;
}