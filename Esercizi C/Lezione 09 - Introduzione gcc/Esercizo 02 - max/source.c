#include <stdio.h>

int main(){
    int a=0, b=0;
    printf("Inserisci un numero: ");
    scanf("%d", &a);
    printf("Inserisci un altro numero: ");
    scanf("%d", &b);
    printf("Il massimo è %d\n", a>b?a:b);
    return 0;
}