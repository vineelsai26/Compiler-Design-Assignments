a5: a5.l a5.y
	bison -d a5.y
	flex a5.l
	cc -o $@ a5.tab.c lex.yy.c -lfl -w
	./a5

clean :
	rm -f *.tab.c *.yy.c *.tab.h a5