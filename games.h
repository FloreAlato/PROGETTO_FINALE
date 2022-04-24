//
// Created by Davide Flore on 21/01/2022.
//

#include "main.h"
#include "morra_cinese.h"

#ifndef INC_66174_FLORE_DAVIDE_GAMES_H
#define INC_66174_FLORE_DAVIDE_GAMES_H

#endif //INC_66174_FLORE_DAVIDE_GAMES_H




int indovina_il_numero(int n, int players[n]) {

    bool worth_it = find_players(n, players);
    int winner;

    if(!worth_it) {

        winner = rand() % n;
        //printf("\n\nnon vale neanche la pena giocare...\n\n");
    } else {

        int guess = rand() % 1000;
        int num, i, low = 0, high = 999;
        bool won = false;

        printf("\nHo scelto un numero fra 0 e 999! Indovinate!!\n");
        //printf("(ho scelto %d)\n", guess);


        while(won == false) {

            i = 0;

            while(i < n && won == false) {

                printf("\n[%s]: ", print_player(players[i]));

                if(players[i] < 0) {

                    num = get_int(" ", 0, 999);
                } else {

                    num = low + (high - low) / 2;

                    printf("%d!\n", num);
                }

                if(num == guess) {

                    winner = i;
                    printf("\n\n%s vince!!", print_player(players[i]));
                    won = true;
                } else if(num > guess) {

                    high = num;
                    printf("di meno...\n");
                } else {
                    low = num;
                    printf("di piu'...\n");
                }

                i++;
            }
        }
    }

    return players[winner];
}








int pari_o_dispari(const int players[2]) {

    int winner = 10;
    bool odd, even = false;
    int first, second, sum;

    if(players[0] >= 0 && players[1] >= 0) {

        winner = players[rand() % 3];
    } else {

        char opt[2][10] = {"pari", "dispari"};

        //turno 1
        if(players[0] < 0) {
            odd = choice_string("\nPari o dispari?\n[Here]: ", &opt[0]);

            printf("\nPerfetto! Quindi vincerai se la somma sara' %s", opt[odd]);

            first = get_int("\nQuante dita butti?\n[Tu]: ", 0, 5);
        } else {
            printf("\nPari o dispari?\n[other]: ");
            odd = rand() % 2;
            printf("%s!", opt[odd]);

            printf("\n\nQuante dita butti?\n[Tu]: ");
            first = rand() % 6;
            printf("%d!", first);
        }


        //turno 2
        if(players[1] < 0) {
            second = get_int("\n\nE tu, quante dita butti?\n[Tu]: ", 0, 5);
        } else {
            printf("\n\nE tu, quante dita butti?\n[Tu]: ");
            second = rand() % 6;
            printf("%d!", second);
        }


        //finale
        sum = first + second;
        printf("\n\nLa somma di %d e %d e' %d!!", first, second, sum);
        even = sum % 2 == 0;

        if(odd == even) {
            printf("\nIl vincitore e' %d!!!", players[0]);
            winner = 0;
        } else {
            printf("\nIl vincitore e' %d!!!", players[1]);
            winner = 1;
        }
    }


    return winner;
}









int dadi(const int players[2]) {


    srand(time(NULL));

    int winner, first, second, sum_first = 0, sum_second = 0, sum;
    bool continua = true;

    first = rand() % 1;

    if(first == 1) {
        second = 0;
    } else {
        second = 1;
    }

    do {
        //primo turno
        sum = rand() % 13;
        printf("\n E' uscito %d", sum);
        getchar();
        if(sum < sum_first) {
            continua = false;
            winner = second;
        } else {
            sum_first = sum;
        }

        //secondo turno
        if(continua) {

            sum = rand() % 13;
            printf("\n E' uscito %d", sum);
            if(sum < sum_second) {
                continua = false;
                winner = first;
            } else {
                sum_second = sum;
            }
        }

    } while(continua);


    return winner;
}












