bison: flex.l bison.y
	bison -d bison.y
	flex flex.l
	cc -o $@ bison.tab.c lex.yy.c -lfl -w
	./bison

clean :
	rm -f *.tab.c *.yy.c *.tab.h bison