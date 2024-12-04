#include <stdio.h>
#include <pthread.h>

// Stamperà una sequenza casuale di c e x

void* char_print(void* unused){
    while(1) printf("%c", 'x');
    return 0;
}

int main(){
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &char_print, NULL);
    while(1) printf("%c", 'c');
    return 0;
}