#include "ladro.h"

void* azioni_ladro(void* data_in){
    srand(time(NULL));
    Data* data = (Data*) data_in;
    Pos pos = data->pos_iniziale;
    int r;
    while(1){
        r = rand()%4;
        switch(r){
            case 0: pos.x++; break;
            case 1: pos.x--; break;
            case 2: pos.y++; break;
            case 3: pos.y--; break;
            default: break;
        }
        while(*(data->counter)>=DIM_BUFFER-1);
        data->mutex = 1;
        data->buffer[*(data->counter)] = pos;
        *(data->counter)++;
        data->mutex = 0;
        usleep(5000);
    }
    return 0;
}