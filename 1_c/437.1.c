#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isPunctuator(char ch)
{
    if (ch == ',' || ch == ';' || ch == '>' || ch == '(' || ch == ')' ||ch == '[' || ch == ']' || ch == '{' || ch == '}')
        {
            return true;
        }
    return false;
}
bool isStartOfComment(char ch)
{
    if (ch == '/' || ch == '*')
        {
            return true;
        }
    return false;
}
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' ||
       ch == '>' || ch == '<' ||
        ch == '=' || ch == '|' || ch == '&')
    {
       return true;
    }
    return false;
}
bool isKeyword(char* str){
	char keywords[51][20] = {"Abstract","boolean","Byte","Break","class",
"Case","catch","char","continue","default","args",
"Do","double","else","Extends","final",
"Finally","float","for","if","implements",
"import","instanceof","int","Interface","long",
"Native","newpackage","rrivate","protected",
"public","return","Short","Static","super",
"switch","synchronized","this","Throw","throws",
"Transient","try","void","Volatile","while",
"assert","const","enum","Goto","strictfp"};
	for (int i = 0; i < 51; ++i)
	{
		if(strcmp(keywords[i], str) == 0){
			return true;
		}
		
	}
	return false;
}


bool isComment(char* line)
{
 
    if (line[0] == '/' && line[1] == '/'
        && line[2] != '/') {
    	
 				printf(" %s => single Line comment\n",line);
                return true;
    }
 
    if (line[strlen(line) - 2] == '*'
        && line[strlen(line)  - 1] == '/') {
 
        printf(" %s => multi-line comment\n",line);
        return true;
    }
 
    return false;
}

int main(int argc, char const *argv[])
{
	FILE *fp;
	char ch,words[150];
	fp = fopen("sample.java","r");
	int i,j=0;

	while((ch = fgetc(fp)) != EOF){
	   if (isOperator(ch))
	   {
	   		printf("%c => Operator\n",ch);
	   	
	   }
	   if (isPunctuator(ch))
	   {
	   		printf("%c => Seperator\n",ch);
	   	
	   }

	   if(isalnum(ch) || isStartOfComment(ch)){
	   		words[j++] = ch;
	   }
	   else if((ch == ' ' || ch == '\n' || ch == '(') && (j != 0))
	   {
		   words[j] = '\0';
		   j = 0;
		     
		   if(isKeyword(words) == 1){
		   		printf("%s => keyword\n", words);
		   }
		   else if (isComment(words))
		   {
		   		printf("\n");
		   }
		   else{
		   		printf("%s => indentifier\n", words);
		   }
	   	}
  
	}
	fclose(fp);
	return 0;
}