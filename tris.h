//
// Created by Davide Flore on 30/04/2022.
//

#ifndef PARI_O_DISPARI_H_TRIS_H
#define PARI_O_DISPARI_H_TRIS_H

#endif //PARI_O_DISPARI_H_TRIS_H

#include "murra.h"


int tris(const int[2]);
void print_tris(char[4][4]);
void turno(char *, int[]);
int char_to_int(char);





int tris(const int players[2]) {

    bool start;
    int coordinate[2] = {0, 0};
    char table[4][4] = {'A', '-', '-', '-',
                        'B', '-', '-', '-',
                        'C', '-', '-', '-',
                        ' ', '1', '2', '3'};

    //choose the lowest index to start
    if(abs(players[0]) <= abs(players[1])) {
        start = false;
    } else {
        start = true;
    }

    print_tris(&table[0]);

    if(players[start] < 0) {
        turno("\nInserisci una lettera e un numero: ", coordinate);

        if(table[coordinate[0]][coordinate[1]] == '-') {
            table[coordinate[0]][coordinate[1]] = 'X';
        } else {
            printf("\nCASELLA OCCUPATA!!!");
        }
    }

    print_tris(&table[0]);

    return 0;
}


void turno(char *query, int arr[]) {

    char answer[3];
    bool wrong = false;

    do {
        wrong = false;
        printf("%s", query);
        scanf(" %s", answer);

        if(is_numeric(answer[1]) && char_to_int(answer[1]) <= 3 && char_to_int(answer[1]) >= 1) {
            switch (answer[0]) {
                case 'A':
                    arr[0] = 0;
                    break;
                case 'B':
                    arr[0] = 1;
                    break;
                case 'C':
                    arr[0] = 2;
                    break;
            }
            arr[1] = char_to_int(answer[1]);

        } else {
            printf("\nFORMAT SBAGLIATO!");
            wrong = true;
        }

    } while(wrong == true);
}





void print_tris(char table[4][4]) {

    printf("\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%c  ", table[i][j]);
        }
        printf("\n");
    }
}



int char_to_int(char c) {

    return (int)c - 48;
}



// FINIREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE