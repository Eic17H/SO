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
    int* mutex;
}Data;

typedef struct{
    Data* buffer;
    int* mutex;
    int* head;
    int* tail;
    Data* data;
}Pass;

bool codavuota(int head, int tail){
    return (tail+1-head)%DIM_BUFFER==0;
}

bool codapiena(int head, int tail){
    return (head+1-tail)%DIM_BUFFER==0;
}

void* azioniL(void* data_in){
    srand(time(NULL));
    Pass* data = (Pass*) data_in;
    Pos pos = data->data->pos;
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
        while(codapiena(*(data->head), *(data->tail)) || *(data->mutex)) printf("qua\n");
        *(data->mutex) = 1;
        data->data->pos = pos;
        (data->buffer)[*(data->tail)] = *(data->data);
        *(data->tail) = (*(data->tail)+1)%DIM_BUFFER;
        *(data->mutex) = 0;
        usleep(5000);
    }
}

int main(){
    int mutex = 0;
    Data buffer[DIM_BUFFER];
    int head=0;
    int tail=(-1)%DIM_BUFFER;
    Pass* passL = malloc(sizeof(Pass));
    pthread_t idL;
    Data* datiL = malloc(sizeof(Data));
    (*datiL).pos.x = 3;
    (*datiL).pos.y = 3;
    (*datiL).mittente = LADRO;
    passL->buffer = buffer;
    passL->head = &head;
    passL->tail = &tail;
    passL->mutex = &mutex;
    passL->data = datiL;
    pthread_create(&idL, NULL, &azioniL, passL);
    while(1){
        while(codavuota(head, tail) || mutex);
        mutex = 1;
        printf("%d   %d\n", buffer[head].pos.x, buffer[head].pos.y);
        head = (head+1)%DIM_BUFFER;
        mutex = 0;
    }
}