// Un thread ne crea 5 che stampano caratteri concorrentemente
// Il carattere e il numero di caratteri sono passati come argomento

#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 10000

typedef struct{
    int n;
    char c;
}Args;

void* char_print(Args *args){
    int i = args->n;
    while(i --> 0) {printf("%c", args->c); usleep(0);}
    printf("\nOK_%c\n", args->c);
    return 0;
}

int main(){
    // Gli argomenti dei 5 thread
    Args a = {N, 'a'};
    Args e = {N, 'e'};
    Args i = {N, 'i'};
    Args o = {N, 'o'};
    Args u = {N, 'u'};
    // Gli ID dei 5 thread
    pthread_t thread_id_a;
    pthread_t thread_id_e;
    pthread_t thread_id_i;
    pthread_t thread_id_o;
    pthread_t thread_id_u;
    // Attiva i 5 thread
    pthread_create(&thread_id_a, NULL, &char_print, &a);
    pthread_create(&thread_id_e, NULL, &char_print, &e);
    pthread_create(&thread_id_i, NULL, &char_print, &i);
    pthread_create(&thread_id_o, NULL, &char_print, &o);
    pthread_create(&thread_id_u, NULL, &char_print, &u);
    // Attende i 5 thread
    pthread_join(thread_id_a, NULL);
    pthread_join(thread_id_e, NULL);
    pthread_join(thread_id_i, NULL);
    pthread_join(thread_id_o, NULL);
    pthread_join(thread_id_u, NULL);
    // Termina
    return 0;
}