#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define OBJECT '#'
// Positivo=giù
#define G 0.5
// Tra 1.13 e 1.2 risulta 0 perdita di energia, forse per errori di arrotondamento non è 1
// Sopra 1.2 rimbalza anche sopra e guadagna velocità verticale ogni volta e poi si rompe
#define ELASTICITY 1.1

// Un carattere si sposta a destra a velocità costante e rimbalza elasticamente
int main()
{
    float x=2, y=2;
    int c;
    // Se devo aggiungere input
    char input = ' ';
    // Cose normali da fare sempre
    initscr(); noecho(); curs_set(0); cbreak(); keypad(stdscr, 1); box(stdscr, ACS_VLINE, ACS_HLINE); mvaddch((int)y, (int)x, OBJECT); refresh();
    // Cambia carattere a ogni "frame"
    int i = 0;
    // Velocità corrente, parte da 0
    float spd = 0;
    while (1){
	// I caratteri vanno dalla A alla Z e ricominciano
	i = (i+1)%26;
        mvaddch((int)y, (int)x, i+'A');
	// Formula del movimento uniformemente accelerato, diciamo
        spd += G; y += spd;
	// Se tocca il fondo, rimbalza elasticamente (=perdendo energia nell'impatto)
        if ((int)y >= LINES-2 || (int)y <= 1)
            spd = (int) -(((float)spd)*(ELASTICITY));
	// Visualizza, aspetta, sposta a destra
        refresh();
	sleep(1);
	x++;
    }
}
