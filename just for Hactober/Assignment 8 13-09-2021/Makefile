run:	437.y 437.l
	@bison -d 437.y
	@flex -o 437.lex.c 437.l
	@gcc -o parser 437.lex.c 437.tab.c -w -lfl
	@./parser