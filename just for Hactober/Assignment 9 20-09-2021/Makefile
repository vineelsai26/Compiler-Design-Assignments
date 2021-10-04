a.out: 437.tab.c++ lex.yy.c symTab.o
	g++ 437.tab.c++ lex.yy.c symTab.o
437.tab.c++ : 437.y++
	bison -d -v 437.y++
lex.yy.c : 437.l
	flex 437.l
symTab.o : symTab.c++ symTab.h
	g++ -Wall -c symTab.c++
clean:
	rm a.out 437.output 437.tab.c++ 437.tab.h++ symTab.o lex.yy.c

