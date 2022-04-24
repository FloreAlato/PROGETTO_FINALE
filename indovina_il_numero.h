//
// Created by Davide Flore on 24/04/2022.
//

#ifndef HANDY_H_INDOVINA_IL_NUMERO_H
#define HANDY_H_INDOVINA_IL_NUMERO_H

#endif //HANDY_H_INDOVINA_IL_NUMERO_H

#include <stdbool.h>


int indovina_il_numero(int size, int players[size]) {

    int winner = 0, number, min = 0, max = 999, i, guess;
    bool won = false;

    number = rand() % 1000;

    printf("\nHo scelto un numero da 0 a 999, indovinatelo!");

    while(won == false) {

        i = 0;
        while(i < size && won == false) {

            if(players[1] < 0) {
                //turno giocatore
            } else {
                guess = min + (max - min) / 2;//rivedere
            }
        }
    }

    return winner;
}