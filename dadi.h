//
// Created by Davide Flore on 30/04/2022.
//

#ifndef PARI_O_DISPARI_H_DADI_H
#define PARI_O_DISPARI_H_DADI_H

#endif //PARI_O_DISPARI_H_DADI_H


#include "pari_o_dispari.h"


int dadi(const int players[2]) {

    int somma = 0, winner;
    int precedente[2] = {0, 0};
    bool start = rand() % 2;
    bool won = false;

    do {
        if(players[start] < 0) {
            printf("\nTira i dadi, %d!", players[start]);
            getchar();
        }
        somma = rand() % 13;

        if(somma >= precedente[start]) {
            printf("\nHai fatto %d, bel lancio!", somma);
            precedente[start] = somma;
        } else {
            printf("\nAia! hai fatto %d, sei squalificato!", somma);
            winner = !start;
            won = true;
        }

        start = !start;
    } while(won == false);

    return winner;
}


//rendere divertente da giocare (anche se questo è il meno peggio)