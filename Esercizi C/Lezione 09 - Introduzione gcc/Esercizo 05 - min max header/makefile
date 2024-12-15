code_makefile: clean main.o min.o max.o min.h max.h
	gcc main.o min.o max.o -o code_makefile
main.o: main.c min.h max.h
	gcc -c main.c
max.o: max.c max.h
	gcc -c max.c
min.o: min.c min.h
	gcc -c min.c
clean:
	rm -f ./*.o