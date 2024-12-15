#ifndef TYPES_H
#define TYPES_H

#define DIM_BUFFER 10

typedef struct{
    int x;
    int y;
}Pos;

typedef struct{
    Pos pos_iniziale;
    Pos* buffer;
    int* counter;
    int mutex;
}Data;

#endif