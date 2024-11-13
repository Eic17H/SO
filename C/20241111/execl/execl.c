#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	printf("I file:\n");
	execl("/bin/ls", "-l", NULL);
	printf("Errore: non dovresti essere qui\n");
	exit(-1);
}
