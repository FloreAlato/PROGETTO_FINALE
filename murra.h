//
// Created by Davide Flore on 30/04/2022.
//

#ifndef PARI_O_DISPARI_H_MURRA_H
#define PARI_O_DISPARI_H_MURRA_H

#endif //PARI_O_DISPARI_H_MURRA_H


#include "dadi.h"




int murra(const int players[2]) {

    int scelta1, scelta2, somma1, somma2, winner;
    bool won = false;

    do {
        if(players[0] < 0) {
            scelta1 = get_int("\nButta un numero: ", 0, 5);
            somma1 = get_int("\nE ora un pronostico: ", 1, 10);
        } else {
            scelta1 = rand() % 6;
            somma1 = (rand() % 10) + 1;
        }

        if(players[0] < 0) {
            scelta2 = get_int("\nButta un numero: ", 0, 5);
            somma2 = get_int("\nE ora un pronostico: ", 1, 10);
        } else {
            scelta2 = rand() % 6;
            somma2 = (rand() % 10) + 1;
        }

        if(somma1 == somma2 && somma1 == scelta1 + scelta2) {
            printf("\nPareggio! Ci avete preso entrambi! Rifacciamola!");
        } else if(somma1 == scelta1 + scelta2) {
            printf("\nCi hai preso, %d!", players[0]);
            winner = 0;
            won = true;
        } else if(somma2 == scelta1 + scelta2) {
            printf("\nCi hai preso, %d!", players[1]);
            winner = 1;
            won = true;
        } else {
            printf("\nNiente, prossimo round!");
        }

    } while(won == false);

    return winner;
}