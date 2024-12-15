#include <stdio.h>
#include "min.h"
#include "max.h"

int main(){
    int a=0, b=0, o=0;
    printf("Inserisci un numero: ");
    scanf("%d", &a);
    printf("Inserisci un altro numero: ");
    scanf("%d", &b);
    printf("Inserisci il numero per l'opzione: ");
    scanf("%d", &o);
    if(o) printf("Il minimo e' %d\n", min(a,b));
    else printf("Il massimo e' %d\n", max(a,b));
    return 0;
}