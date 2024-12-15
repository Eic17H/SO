code_makefile: clean main.o max.o max.h
	gcc main.o max.o -o code_makefile
main.o: main.c max.h
	gcc -c main.c
max.o: max.c max.h
	gcc -c max.c
clean:
	rm -f *.o