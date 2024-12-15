#include "funzioni.h"

int prodotto(int* array, int lung){
    int out=1;
    for(int i=0; i<lung; i++)
        if(array[i] %2 == 1)
            out *= array[i];
    return out;
}