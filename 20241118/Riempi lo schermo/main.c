#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#define OBJECT '#'

// Riempie lo schermo con OBJECT e si esce con q

int main() {
    srand(time(0));
    initscr(); noecho(); curs_set(0); cbreak(); timeout(0);
    keypad(stdscr, 1);
    box (stdscr , ACS_VLINE , ACS_HLINE ) ;
    int x  = 1 , y  = 1, r;
    mvaddch ( y , x , OBJECT ) ; refresh() ;
    do{
        //mvaddch(r%LINES, (r/LINES)%COLS, OBJECT); refresh();
        //r = (r + 1)%(LINES*COLS);
        y=rand()%(LINES-2)+1;
        x=rand()%(COLS-2)+1;
        mvaddch(y, x, OBJECT); refresh();
        usleep(5000);
    }while(getch()!='q');
    endwin();
    return 0;
}
