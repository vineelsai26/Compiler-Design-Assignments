#include "lex.h"
#include "parser.h"
#include "backend.h"

int main()
{
    printf("Enter the expression : ");
    scanf("%s", expr);
    ASTnode_t *ptr;
    initParserBackend();
    if (parser(&ptr))
    {
        int ans = compute(ptr);
        printf("%d\n", ans);
    }
    else
    {
        printf("Invalid expression.\n");
    }
}