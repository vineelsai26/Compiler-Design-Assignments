a.out: 498.tab.c++ lex.yy.c
	g++ 498.tab.c++ lex.yy.c
	./a.out
498.tab.c++ : 498.y++
	bison -d -v 498.y++
lex.yy.c : 498.l
	flex 498.l
clean:
	rm a.out 498.output 498.tab.c++ 498.tab.h++ lex.yy.c