#ifndef COMUNE_H
#define COMUNE_H

#include <ncurses.h>

typedef struct{
    int x;
    int y;
}Pos;

void controlla(int *x, int *y);

#endif