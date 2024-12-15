#include <stdio.h>
#include "max.h"

// TODO: Chiedi perché clean non funziona su makefile

int main(){
    int a=0, b=0;
    printf("Inserisci un numero: ");
    scanf("%d", &a);
    printf("Inserisci un altro numero: ");
    scanf("%d", &b);
    printf("Il massimo è %d\n", max(a,b));
    return 0;
}