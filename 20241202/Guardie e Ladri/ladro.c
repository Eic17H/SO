#include "ladro.h"

void movimentoL(int *x, int *y){
    int dir = -1;
    char c = 1;
    if(258 <= c && c <= 261) dir = c%258;
    switch(dir){
        case 0: (*y)+=1; break;
        case 1: (*y)-=1; break;
        case 2: (*x)-=2; break;
        case 3: (*x)+=2; break;
    }
}

void azioniLadro(int pipe_fds[2], Pos pos){
    noecho();
    int x = pos.x;
    int y = pos.y;
    movimentoL(&x, &y);
    controlla(&x, &y);
    close(pipe_fds[0]);
    Pos posizione;
    posizione.x = x;
    posizione.y = y;
    int aaaaa[2];
    aaaaa[0]=x; aaaaa[1]=y;
    write(pipe_fds[1], aaaaa, 2);
}