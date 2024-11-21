#include <stdlib.h>
#include <curses.h>
#define OBJECT '#'
#define G -9.8
#define ELASTICITY 0.5

int main()
{
    // Cose normali da fare sempre
    int x=COLS/2, y=0, c;
    char input = ' ';
    initscr(); noecho(); curs_set(0); cbreak(); keypad(stdscr, 1); box(stdscr, ACS_VLINE, ACS_HLINE); mvaddch(y, x, OBJECT); refresh();
    
    int spd = 0;
    while (1)
    {
        mvaddch(ROWS, COLS, spd);
        input = getch();
        if (input == 'a'){
            y = 0;
            spd = 0;
        }
        mvaddch(y, x, OBJECT);
        spd += G;
        y += spd;
        if (y >= LINES)
            spd = -spd / 2;
        mvaddch(y, x, OBJECT);
        refresh();
    }
}