out: clean main.o ladro.o types.h
	gcc main.o ladro.o -l ncurses -l pthread -o GLAth
main.o: main.c ladro.h types.h
	gcc -c main.c
ladro.o: ladro.c ladro.h types.h
	gcc -c ladro.c
clean:
	rm -f *.o