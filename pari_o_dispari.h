//
// Created by Davide Flore on 30/04/2022.
//

#ifndef MAIN_C_PARI_O_DISPARI_H
#define MAIN_C_PARI_O_DISPARI_H

#endif //MAIN_C_PARI_O_DISPARI_H


#include "morra_cinese.h"






int pari_o_dispari(const int players[2]) {

    bool dispari;
    int first, second, sum;

    if(players[0] < 0) {
        dispari = choice_string("\nPari o dispari?\n[Tu]: ", &par[0]);

        first = get_int("\nPerfetto! Che numero butti?\n[Tu]: ", 0, 5);
    } else {
        dispari = rand() % 2;
        first = rand() % 6;
    }

    if(players[1] < 0) {
        second = get_int("\nE tu cosa butti?\n[Tu]: ", 0, 5);
    } else {
        second = rand() % 6;
    }

    sum = first + second;

    if(sum % 2 == 0 && !dispari) {
        return 0;
    } else {
        return 1;
    }
}


//rendere divertente da giocare