#include "guardia.h"

void movimentoG(int *x, int *y){
    int dir = -1;
    char c = getch();
    if(258 <= c && c <= 261) dir = c%258;
    switch(dir){
        case 0: (*y)+=1; break;
        case 1: (*y)-=1; break;
        case 2: (*x)-=2; break;
        case 3: (*x)+=2; break;
    }
}

void azioniGuardia(int pipe_fds[2], Pos pos){
    // Ho mischiato pipe e riferimenti, mi arrendo
    int x = pos.x;
    int y = pos.y;
    movimentoG(&x, &y);
    controlla(&x, &y);
    close(pipe_fds[0]); 
    write(pipe_fds[1], {x, y}, sizeof(Pos));
}