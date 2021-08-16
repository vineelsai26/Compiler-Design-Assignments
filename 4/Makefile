objfiles = main.o parser.o lex.o backend.o

a.out: $(objfiles)
	cc $(objfiles)

main.o: 498.main.c
	cc -Wall -c 498.main.c -o main.o

parser.o: parser.c
	cc -Wall -c parser.c

lex.o: lex.c
	cc -Wall -c lex.c

backend.o: backend.c
	cc -Wall -c backend.c

clean : 
	rm a.out $(objfiles)
