#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>

int main(){
    // Il solito
        initscr();
        noecho();
        curs_set(0);
        cbreak();
        keypad(stdscr, 1);
        box(stdscr, ACS_VLINE, ACS_HLINE);
        refresh();
        srand(time(NULL));
    
    int pipe_fds_guardia[2];
    int pipe_fds_ladro[2];

    if(pipe(pipe_fds_guardia) == -1) {
        perror("Pipe call");
        exit(1);
    }
    if(pipe(pipe_fds_ladro) == -1) {
        perror("Pipe call");
        exit(1);
    }

    pid_t pid;
    pid=fork();

    // TODO: continua con questo
    
    if(fork==0) while(1){

    }
}