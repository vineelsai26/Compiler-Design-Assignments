#include "lex.h"
#include "parser.h"
#include "backend.h"

int main() {
	printf("Enter an expression (format example - ((a=8+r,b=e+a))):\n");
    fgets(expr, 1000, stdin);
    ASTnode_t *ptr;
    initParserBackend();
    if (parser(&ptr)) {
        int ans = compute(ptr);
        if (!invalid_expr)
            printf("The evaluated answer of the Expression is : %d\n", ans);
    }
    else {
        printf("Invalid format of the expression.\n");
    }
}
