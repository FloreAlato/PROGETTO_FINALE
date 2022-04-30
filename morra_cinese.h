//
// Created by Davide Flore on 21/04/2022.
//

#ifndef MAIN_C_MORRA_CINESE_H
#define MAIN_C_MORRA_CINESE_H

#endif //MAIN_C_MORRA_CINESE_H

#include "indovina_il_numero.h"





//struttura che conterrà i gesti del gioco
//(cfs sta per carta, forbici, sasso)
struct morra {
    int cfs;
    struct morra *prossimo;
};



//dichiarazioni delle funzioni
//non sarebbero necessarie, ma le metto per estetica, giusto per scrivere le funzioni nell'ordine giusto
int morra_cinese(const int[2]);
struct morra turno_morra(int, struct morra, struct morra, struct morra);





//funzione che gestisce il gioco della morra cinese
//prende un array di due interi e restituisce un intero
/*essendo un gioco di coppia, prende una coppia di giocatori come input
 *e restituisce l'indice del vincitore nel gruppo stesso*/
int morra_cinese(const int players[2]) {

    //inizializza le strutture per i tre gesti possibili
    struct morra carta, forbici, sasso;
    //assegna i campi in modo da assegnarli circolarmente
    //carta punta a forbici, che punta a sasso, che punta a carta
    //così posso determinare il vincitore in base ai gesti dei due giocatori
    carta.cfs = 0;
    carta.prossimo = &forbici;
    forbici.cfs = 1;
    forbici.prossimo = &sasso;
    sasso.cfs = 2;
    sasso.prossimo = &carta;

    //intero che conterrà l'indice del vincitore
    int winner;
    //strutture morra che conterrano i segni dei due giocatori
    struct morra first, second;

    //assegna alle due strutture l'input del giocatore o valori casuali usando l'apposita funzionw
    first = turno_morra(players[0], carta, forbici, sasso);
    second = turno_morra(players[1], carta, forbici, sasso);


    //assegna il vincitore in base ai valori di first e second
    //penso che sia chiaro ormai come funzioni
    if(second.cfs == first.prossimo->cfs) {
        winner = 1;
    } else {
        winner = 0;
    }

    //infine ritorna l'indice del vincitore nell'array
    return winner;
}





//funzione che svolge un turno al gioco morra cinese
//prende un intero, tre strutture morra e restituisce una struttura morra
/*la funzione principale prevede che per ogni turno venga raccolto un input di tipo struttura morra
 *questa funzione fa proprio quello, prendendolo dall'utente o generandolo casualmente a seconda della situazione*/
struct morra turno_morra(int pla, struct morra carta, struct morra forbici, struct morra sasso) {

    //intero t che conterrà l'input utente o il numero casuale
    int t;
    //struttura morra che verrà restituita dalla funzione
    struct morra turn;

    //controlla che il numero giocatore appartenga ad un utente o al programma (vedi README.txt)
    if(pla < 0) {
        //se il giocatore è umano, raccoglie un intero compreso fra 0 e 2
        t = get_int("\n[0] Carta, [1] Forbici, [2] Sasso\n[Tu]: ", 0, 2);
    } else {
        //altrimenti lo genera casualmente
        t = rand() % 3;
    }

    //una volta raccolto, lo usa come indice per assegnare a turn il gesto corrispondente
    switch (t) {
        case 0:
            turn = carta;
            break;
        case 1:
            turn = forbici;
            break;
        case 2:
            turn = sasso;
            break;
        default:
            //non succede, ma se succede ho messo un valore a saco giusto per evitarmi un warning
            turn.cfs = 3;
            //inoltre stampa anche un messaggio di errore
            printf("\nERRORE\n");
            break;
    }

    //infine ritorna il valore scelto
    return turn;
}


//rendere piacevole da giocare