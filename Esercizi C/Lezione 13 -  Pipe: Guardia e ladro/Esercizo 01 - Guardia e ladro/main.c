#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>

#define START_G {1,1}
#define START_L {5,5}

typedef struct{
    int x;
    int y;
}Pos;

int main(){
    // Il solito
        srand(time(NULL));
    
    int pipe_fds_guardia[2];
    int pipe_fds_ladro[2];
    int in[2];

    if(pipe(pipe_fds_guardia) == -1) {
        perror("Pipe call");
        exit(1);
    }
    if(pipe(pipe_fds_ladro) == -1) {
        perror("Pipe call");
        exit(1);
    }

    pid_t pid;

    Pos posG=START_G, posL=START_L;

    // Non ho capito se vanno fatte pipe separate

    pid=fork();
    if(pid < 0) {perror("fork call"); _exit(2);}
    else if(pid!=0) while(1){
        pid=fork();
        if(pid < 0) {perror("fork call"); _exit(2);}
        else if(pid!=0) while(1){
            // Padre: gestione generale
            while(1){
                close(pipe_fds_guardia[1]);
                read(pipe_fds_guardia[0], in, 2*sizeof(int));
                printf("%d %d\n", in[0], in[1]);
            }
        }else{
            // Figlio: guardia
            while(1){
                in[0] = rand()%10;
                in[1] = rand()%10;
                close(pipe_fds_guardia[0]);
                write(pipe_fds_guardia[1], in, 2*sizeof(int));
            }
        }
    }else{
        // Figlio: ladro
        while(1);
    }
}