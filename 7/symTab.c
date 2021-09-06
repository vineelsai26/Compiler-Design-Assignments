#include "symTab.h"

symRec symTab[SIZE];

void initSymTab()
{
    for (int i = 0; i < SIZE; i++)
    {
        symTab[i].def = 0;
    }
}

int updateSymTab(int index, int val)
{
    symTab[index].def = 1;
    symTab[index].val = val;
    return val;
}

int getVal(int index, int *vP)
{
    if (!symTab[index].def)
        return 0;
    *vP = symTab[index].val;
    return 1;
}
