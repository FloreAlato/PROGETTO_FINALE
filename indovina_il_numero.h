//
// Created by Davide Flore on 24/04/2022.
//

#ifndef HANDY_H_INDOVINA_IL_NUMERO_H
#define HANDY_H_INDOVINA_IL_NUMERO_H

#endif //HANDY_H_INDOVINA_IL_NUMERO_H

#include "main.h"





//funzione che gestisce il gioco di indovina il numero
//prende un array di interi e la sua dimensione intera e restituisce un intero
/**/
int indovina_il_numero(int size, const int players[size]) {

    int winner = 0, number, min = 0, max = 999, i, guess;
    bool won = false;

    number = rand() % 1000;

    printf("\nHo scelto un numero da 0 a 999, indovinatelo! (%d)", number);

    while(won == false) {

        i = 0;
        while(i < size && won == false) {

            if(players[i] < 0) {
                guess = get_int("\nNumeo: ", 0, 999);
            } else {
                guess = min + (max - min) / 2;
            }

            if(guess == number) {
                winner = i;
                won = true;
            } else if(number > guess) {
                min = guess;
                printf("\nPiu' grande...\n");
            } else {
                max = guess;
                printf("\nPiu' piccolo...\n");
            }

            i++;
        }
    }

    return winner;
}


//rendere piacevole da giocare