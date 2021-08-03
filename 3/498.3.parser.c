#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *fin = fopen("output.txt", "r");
    char line[1000];

    if (fin == NULL)
    {
        printf("File not found\n");
    }
    else
    {
        int lineNo = 1;
        char par[1000];
        int parNo = 0;
        while (fgets(line, sizeof(line), fin) != NULL)
        {
            char word[1000][1000];
            int i = 0;
            char *token = strtok(line, "<");
            while (token != NULL)
            {
                strcpy(word[i], token);

                char id[100];
                if (word[i][0] == 'i' && word[i][1] == 'd')
                {
                    word[i][strlen(word[i]) - 1] = '\0';
                    strcpy(id, word[i] + 3);
                    char ch = id[0];
                    int alnumCounter = 0;
                    while (ch != '\0')
                    {
                        ch = id[i];
                        if (isalpha(ch))
                        {
                            alnumCounter++;
                        }
                        i++;
                    }

                    if (alnumCounter >= 1 && !isalpha(id[0]) && strlen(id) > 1)
                    {
                        printf("Line %d: invalid keyword %s\n", lineNo, id);
                    }
                }

                if (word[i][0] == 'o' && word[i][1] == 'p' && word[i][3] == 'i' && word[i][4] == 'n')
                {
                    if (!isalpha(id[0]))
                    {
                        printf("Line %d: invalid Operator %s++ or %s--\n", lineNo, id, id);
                    }
                }

                token = strtok(NULL, "<");
                i++;
            }

            if (word[i - 1][4] != ';' && word[i - 1][4] != '{' && word[i - 1][4] != '}' && word[i - 1][4] != '(' && word[i - 1][4] != ')')
            {
                printf("Line %d: ; excepted\n", lineNo);
            }

            if (word[i - 1][4] != '{' || word[i - 1][4] != '(')
            {
                par[parNo] = word[i - 1][4];
                parNo++;
            }

            if (word[i - 1][4] == '}')
            {
                if (par[parNo] == '{')
                {
                    parNo--;
                }
                else if (par[parNo] == '(')
                {
                    printf("Line %d: ) excepted\n", lineNo);
                }
            }

            if (word[i - 1][4] == ')')
            {
                if (par[parNo] = '(')
                {
                    parNo--;
                }
                else if (par[parNo] == '{')
                {
                    printf("Line %d: } excepted\n", lineNo);
                }
            }
            lineNo++;
        }
        for (int j = 0; j <= parNo; j++)
        {
            if (par[j] == '{')
            {
                printf("Line %d: } excepted\n", lineNo);
            }
            else if (par[j] == '(')
            {
                printf("Line %d: ) excepted\n", lineNo);
            }
        }
    }
    fclose(fin);
}