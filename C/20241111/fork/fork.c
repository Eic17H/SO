#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid;
	printf("Inizio: %d\n", (int)getpid());
	pid=fork();
	if(pid==0) printf("Figlio: %d\n", (int)getpid());
	else if(pid<0) printf("Errore\n");
	else printf("Genitore: %d, figlio: %d\n", (int)getpid(), (int)pid);
}
