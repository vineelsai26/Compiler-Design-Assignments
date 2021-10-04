#include <stdio.h>
#define END 256
#define NUM 257

typedef struct { 
    int tokenClass; 
    int val; 
} token_t;

extern token_t token;
extern void getNextToken(void);