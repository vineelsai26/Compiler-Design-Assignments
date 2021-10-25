run: 498.y 498.l
	bison -d 498.y
	flex  -o 498.lex.c 498.l
	gcc  -o parser 498.lex.c 498.tab.c -lfl -lm
	./parser
