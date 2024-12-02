#include "ladro.h"

void movimentoL(int *x, int *y){
    switch(rand()%4){
        case 0: (*y)+=1; break;
        case 1: (*y)-=1; break;
        case 2: (*x)-=2; break;
        case 3: (*x)+=2; break;
    }
}

void azioniLadro(int pipe_fds[2], Pos pos){
    int x = pos.x;
    int y = pos.y;
    movimentoL(&(pos->x), &(pos->y));
    controlla(&(pos->x), &(pos->y));
    close(pipe_fds[0]); 
    write(pipe_fds[1], pos, sizeof(Pos));
}