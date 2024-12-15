out: clean main.o funzioni.o
	gcc main.o funzioni.o
main.o: funzioni.h main.c
	gcc -c main.c
funzioni.o: prodotto.o somma.o
	gcc prodotto.o somma.o
prodotto.o: funzioni.h prodotto.c
	gcc -c prodotto.c
somma.o: funzioni.h somma.c
	gcc -c somma.c
clean:
	rm -f *.o