out: clean main.o ladro.o guardia.o comune.o
	gcc main.o ladro.o guardia.o comune.o -l ncurses -o Guardia_e_Ladro
	rm -f *.o
main.o: main.c guardia.h ladro.h comune.h
	gcc -c main.c
ladro.o: ladro.c ladro.h comune.h
	gcc -c ladro.c
guardia.o: guardia.c guardia.h comune.h
	gcc -c guardia.c
comune.o: comune.c comune.h
	gcc -c comune.c
clean:
	rm -f *.o