#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "funzioni.h"

int main(){
	pid_t pid;
    pid=fork();
    if(pid==0){
        int array[6];
        printf("Inserisci 6 interi:\n");
        for(int i=0; i<6; i++) scanf("%d", &array[i]);
    }
}