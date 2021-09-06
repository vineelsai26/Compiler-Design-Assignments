#ifndef SYMTAB_H
#define SYMTAB_H
#define SIZE 60

typedef struct
{
    char def;
    int val;
} symRec;

extern symRec symTab[SIZE];
void initSymTab();
int updateSymTab(int index, int val);
int getVal(int index, int *vP);    

#endif
