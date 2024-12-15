#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>

#define DIM_BUFFER 10

typedef enum {GUARDIA, LADRO, AVVOCATO} Mittente;

typedef struct{
    int x;
    int y;
}Pos;

typedef struct{
    Pos pos;
    Mittente mittente;
}Data;

int mutex = 0;
Data buffer[DIM_BUFFER];
int head=0;
int tail=0;

void* azioniL(void* data_in){
    srand(time(NULL));
    Data* data = (Data*) data_in;
    Pos pos = data->pos;
    int r=0;
    while(1){
        r = rand()%4;
        switch(r){
            case 0: pos.x++; break;
            case 1: pos.y++; break;
            case 2: pos.x--; break;
            case 3: pos.y--; break;
            default: break;
        }
        while((head-tail)%DIM_BUFFER<=1 || mutex);
        mutex = 1;
        data->pos = pos;
        buffer[tail] = *data;
        tail = (tail+1)%DIM_BUFFER;
        mutex = 0;
        usleep(5000);
    }
}

int main(){
    pthread_t idL;
    Data* datiL = malloc(sizeof(Data));
    (*datiL).pos.x = 3;
    (*datiL).pos.y = 3;
    (*datiL).mittente = LADRO;
    pthread_create(&idL, NULL, &azioniL, datiL);
    while(1){
        while((head-tail)%DIM_BUFFER<=1 || mutex);
        mutex = 1;
        printf("%d   %d\n", buffer[head].pos.x, buffer[head].pos.y);
        head = (head+1)%DIM_BUFFER;
        mutex = 0;
    }
}