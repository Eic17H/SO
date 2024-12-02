#include "comune.h"

void controlla(int *x, int *y){
    if(*x>COLS-1)  (*x)--;
    if(*x<1)       (*x)++;
    if(*y>LINES-1) (*y)--;
    if(*y<1)       (*y)++;
}