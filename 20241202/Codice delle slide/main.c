#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MSGSIZE 15
char msg1[MSGSIZE] = "Hello world #1";
char msg2[MSGSIZE] = "Hello world #2";
char msg3[MSGSIZE] = "Hello world #2";

int main(){
    char msg_temp[MSGSIZE]; int pipe_fds[2], i; pid_t pid;
    if(pipe(pipe_fds) == -1) {
        perror("Pipe call");
        exit(1);
    }
    pid=fork();
    if(pid < 0) {perror("fork call"); _exit(2);}
    else if(pid == 0) {
        close(pipe_fds[0]);
        write(pipe_fds[1], msg1, MSGSIZE);
        write(pipe_fds[1], msg2, MSGSIZE);
        write(pipe_fds[1], msg3, MSGSIZE);
    } else {
        close(pipe_fds[1]);
        for(i = 0; i < 3; i++) {
            read(pipe_fds[0], msg_temp, MSGSIZE);
            printf("%s\n", msg_temp);
        }
        wait(NULL);
    }
    _exit(0);
}