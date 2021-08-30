#ifndef LEX_H
#define LEX_H

#include <stdio.h>
#define END 256
#define NUM 257
#define ID 258
#define id_struc_H
#define SIZE 60

typedef struct
{
    int tokenClass;
    int val;
} token_t;

typedef struct
{
    char def;
    int val;
} id_struct;

extern id_struct id_struc[SIZE];
void init_id_struc();
int update_id_struc(int index, int val);
int getVal(int index, int *vP);


extern token_t token;
extern char expr[1000];
extern void getNextToken(void);

#endif