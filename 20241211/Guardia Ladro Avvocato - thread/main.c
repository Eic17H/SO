#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

//#include "guardia.h"
#include "ladro.h"
//#include "avvocato.h"
#include "types.h"

#define GUARDIA '#'
#define LADRO '$'
#define AVVOCATO 'A'

int main(){
    // Posizioni iniziali
        const Pos pos0_guardia = {COLS-1, LINES-1};
        const Pos pos0_ladro = {1, 1};
        const Pos pos0_avvocato = {COLS-1, 1};
    
    // Dati
        Data dati_guardia;
        Data dati_ladro;
        Data dati_avvocato;
    
    // Buffer
        Pos buffer_guardia[DIM_BUFFER];
        Pos buffer_ladro[DIM_BUFFER];
        Pos buffer_avvocato[DIM_BUFFER];
        int counter_guardia = 0;
        int counter_ladro = 0;
        int counter_avvocato = 0;
        dati_guardia.buffer = buffer_guardia;
        dati_ladro.buffer = buffer_ladro;
        dati_avvocato.buffer = buffer_avvocato;
        dati_guardia.counter = &counter_guardia;
        dati_ladro.counter = &counter_ladro;
        dati_avvocato.counter = &counter_avvocato;
        dati_ladro.mutex = 0;

    // Creazione thread
        pthread_t thread_id_guardia, thread_id_ladro, thread_id_avvocato;
        //pthread_create(&thread_id_guardia, NULL, &azioni_guardia, &dati_guardia);
        pthread_create(&thread_id_ladro, NULL, &azioni_ladro, &dati_ladro);
        //pthread_create(&thread_id_avvocato, NULL, &azioni_avvocato, &dati_avvocato);
    
    
    // Cose normali da fare sempre
        initscr();
        noecho();
        curs_set(0);
        cbreak();
        keypad(stdscr, 1);
        box(stdscr, ACS_VLINE, ACS_HLINE);

    while(1){
        refresh();
        while(counter_ladro<=0){
            mvaddch(3, 3+counter_ladro, 'X');
            refresh();
        }
        while(counter_ladro>DIM_BUFFER){
            mvaddch(3, 3+counter_ladro, 'H');
            refresh();
        }
        dati_ladro.mutex = 1;
        mvaddch(dati_ladro.buffer[counter_ladro].y, dati_ladro.buffer[counter_ladro].x, LADRO);
        dati_ladro.mutex = 0;
        counter_ladro--;
    }
}