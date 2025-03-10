#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>

#include "guardia.h"
#include "ladro.h"
#include "comune.h"

#define GUARDIA '#'
#define LADRO '$'
#define VUOTO ' '
#define GUARDIA_START_X 1
#define GUARDIA_START_Y 1
#define LADRO_START_X COLS-1
#define LADRO_START_Y LINES-1

int main(){
            // Cose che si fanno sempre
                initscr();
                noecho();
                curs_set(0);
                cbreak();
                keypad(stdscr, 1);
                box(stdscr, ACS_VLINE, ACS_HLINE);
                refresh();
    srand(time(NULL));
    int pipe_fds_ladro[2];
    int pipe_fds_guardia[2];

    if(pipe(pipe_fds_guardia) == -1) {
        perror("Pipe call");
        exit(1);
    }

    int aaaaa[2]={0, 0};

    // Posizioni di base dei personaggi
        Pos guardia={GUARDIA_START_X, GUARDIA_START_Y};
        Pos ladro={LADRO_START_X, LADRO_START_Y};

    pid_t pid;
    pid = fork();
    if(pid<0) {perror("fork call"); _exit(2);}
    else if(pid==0) while(1);// azioniLadro(pipe_fds_ladro, ladro);
    else{
        pid = fork();
        if(pid<0) {perror("fork call"); _exit(2);}
        else if(pid==0) while(1) azioniGuardia(pipe_fds_guardia, guardia);
        else{
            // padre
            while(1){
                //mvaddch(guardia.y, guardia.x, VUOTO);
                mvaddch(ladro.y, ladro.x, VUOTO);
                close(pipe_fds_ladro[1]);
                close(pipe_fds_guardia[1]);
                //read(pipe_fds_ladro[0], aaaaa, 2);
                read(pipe_fds_guardia[0], aaaaa, 2);
                guardia.x += aaaaa[0];
                guardia.y += aaaaa[1];
                mvaddch(guardia.y, guardia.x, GUARDIA);
                //mvaddch(ladro.y, ladro.x, LADRO);
                wait(NULL);
                usleep(50000);
                refresh();
            }
        }
    }
}