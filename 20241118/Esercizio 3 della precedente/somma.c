#include "funzioni.h"
int somma(int* array, int lung){
    int out=0;
    for(int i=0; i<lung; i++)
        if(array[i] %2 == 0)
            out += array[i];
    return out;
}