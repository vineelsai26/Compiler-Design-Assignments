#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *input = fopen("output.txt", "r");
    char line[100];
    int lineNo = 1;
    while (fgets(line, sizeof(line), input) != NULL)
    {
        char word_each[100][100];
        int i = 0;
        char div = "<";
        char *delim = strtok(line, div);
        while (delim != NULL)
        {
            strcpy(word_each[i], delim);
            delim= strtok(NULL, div);
            i++;
        }
        if (word_each[i - 1][4] != ';' && word_each[i - 1][4] != '{' && word_each[i - 1][4] != '}' && word_each[i - 1][4] != '(' && word_each[i - 1][4] != ')')
        {
            printf("Line %d: ; excepted\n", lineNo);
        }
    }
    }
 
    fclose(input);
}