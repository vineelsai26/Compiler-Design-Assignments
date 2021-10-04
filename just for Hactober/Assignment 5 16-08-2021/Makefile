run: a5parse.437.y a5lex.437.l
	bison -d a5parse.437.y
	flex  -o a5lex.437.lex.c a5lex.437.l
	gcc  -o parser a5lex.437.lex.c a5parse.437.tab.c -lfl -w
	./parser