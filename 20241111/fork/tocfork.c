#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid;
	printf("Toc toc\n");
	pid=fork();
	if(pid==0) printf("Race condition\n");
	else if(pid<0) printf("Avanti\n");
	else printf("Chi è?\n");
}
