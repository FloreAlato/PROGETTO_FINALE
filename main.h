//
// Created by Davide Flore on 21/01/2022.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


#ifndef INC_66174_FLORE_DAVIDE_MAIN_H
#define INC_66174_FLORE_DAVIDE_MAIN_H

#endif //INC_66174_FLORE_DAVIDE_MAIN_H






//struttura ProfiloGiocatore, come da consegna

typedef struct {

    int id;
    char nome[64];
    int giochi_giocati;
    int finali_giocate;
    int giochi_vinti;
    int tot_giochi_fatti;
    int tot_giochi_vinti;
} ProfiloGiocatore;


char par[2][10] = {"pari", "dispari"};
char si_no[2][10] = {"si", "no"};






//controlla che una stringa contenga solo caratteri numerici
//prende un puntatore a stringa e ritorna un booleano

bool check_num(char *p) {

    bool correct = true;

    //itera fra i caratteri della stringa
    for(int i = 0; i < strlen(p); i++) {

        //controlla che sia un numero nella tabella ascii
        if(p[i] < 48 || p[i] > 57) {
            printf("\nQuesto non e' un numero\n");
            printf("Dai, ritenta...\n\n");
            correct = false;
            break;
        }
    }

    return correct;
}






//converte una stringa in un intero
//prende un puntatore a stringa e ritorna un intero

int string_to_int(char *str) {

    int n, k, p = 0, total = 0;

    //itera per la stringa da destra verso sinistra escludendo il carattere di fine stringa
    for(k = (int)strlen(str) - 1; k >= 0; k--) {

        //calcola il calore di ogni cifra e lo aggiunde al risultato
        n = (int)str[k] - 48;
        n *= (int)(float)pow(10, p);

        total += n;

        p++;
    }

    return total;
}






//raccoglie un numero compreso in un intervallo
//prende un puntatore a stringa e due interi e restituisce un intero

int get_int(char *query, int min, int max) {

    char num[4];
    int number = 0;
    bool check = true;

    do {
        //pone la domanda e raccoglie la risposta sotto forma di stringa
        printf("%s", query);
        scanf(" %s", num);

        //controlla che la stringa sia numerica con una funzione apposita
        if(check_num(num) == true) {
            //se lo è, la converte in un intero con una funzione apposita
            number = string_to_int(num);
            check = true;
            //poi controlla che sia incluso nell'intervallo
            if(number < min) {
                printf("\nIl numero deve essere maggiore di o uguale a %d\n", min);
                printf("Dai, ritenta...\n\n");
                check = false;
            } else if(number > max) {
                printf("\nIl numero deve essere minore di o uguale a %d\n", min);
                printf("Dai, ritenta...\n\n");
                check = false;
            }
        } else {
            check = false;
        }
        //in ogni altro caso ripete il loop
    } while(check == false);

    return number;
}






//riempire un profilo giocatore
//prende un puntatore a file e restituisce un ProfiloGiocatore

ProfiloGiocatore read_profilo(FILE *file) {

    //predispone un ProfiloGiocaore, lo riempie leggendo dal file e lo ritorna
    ProfiloGiocatore prof;

    fread(&prof.id, sizeof(int), 1, file);
    fread(&prof.nome, sizeof(char), 64, file);
    fread(&prof.giochi_giocati, sizeof(int), 1, file);
    fread(&prof.finali_giocate, sizeof(int), 1, file);
    fread(&prof.giochi_vinti, sizeof(int), 1, file);
    fread(&prof.tot_giochi_fatti, sizeof(int), 1, file);
    fread(&prof.tot_giochi_vinti, sizeof(int), 1, file);

    return prof;
}



void print_profilo(ProfiloGiocatore player, FILE *file) {

    //da scrivere
}






//raccoglie il risultato di una scelta del giocatore facendolo scegliere fra due opzioni
//prende un puntatore a stringa e un array di due stringhe

bool choice_string(char *query, char options[2][10]) {

    bool answer = false;
    bool check = true;

    char choice[20];

    //il loop previene risposte errate
    do {
        //pone la domanda e raccoglie la risposta
        check = true;
        printf("%s", query);
        scanf("%s", choice);

        //restituisce il valore corrispondente alle due risposte esatte, altrimenti ripete il loop
        if(strcmp(choice, options[0]) == 0) {
            answer = false;

        } else if(strcmp(choice, options[1]) == 0) {

            answer = true;
        } else {
            printf("\nPuoi rispondere solo '%s' o '%s'.", options[0], options[1]);
            check = false;
        }
    } while(check == false);

    return answer;
}






//converte il numero di un giocatore in una stringa per estetica
//prende un intero e restituisce un puntatore a stringa

char * print_player(int num) {

    //rimuove il controllo giocatore
    int player = num;
    if(player < 0) {
        player = -player - 1;
    }

    //alloca dinamicamente una stringa per poterla restituire
    char *name = NULL;

    name = (char *)malloc(sizeof(char) * 4);
    if(name == NULL) {
        return "nul\0";
    }

    name[0] = name[1] = name[2] = '0';
    name[3] = '\0';


    //assegna ad ogni carattere della stringa le rispettive cifre tramite divisioni, resti, e conversione ascii
    if(player > 99) {
        name[0] = (char)((player / 100) + 48);
        name[1] = (char)(((player % 100) / 10) + 48);
        name[2] = (char)(((player % 100) % 10) + 48);
    } else if(player > 9) {
        name[1] = (char)((player / 10) + 48);
        name[2] = (char)((player % 10) + 48);
    } else {
        name[2] = (char)(player + 48);
    }

    return name;
}






//stampa n1 gruppi di sventurati in modo ordinato
//prende una matrice di interi e le sue dimensioni

void display_groups(int n1, int n2, int matrix[n1][n2]) {

    int a;

    //stampa i numeri dei gruppi affiancati
    for(a = 0; a < n1; a++) {
        printf("Gruppo %d          ", a + 1);
    }
    printf("\n");
    //itera per la matrice e stampa i disperati a colonne
    for(int b = 0; b < n2; b++) {
        for(int c = 0; c < n1; c++) {
            printf("%s   ", print_player(matrix[c][b]));
        }
        printf("\n");
    }
}






//SCRIVERE DESCRIZIONE QUI

int pick_random(int size, const int list[size], const bool taken[size]) {

    int pick;

    srand(time(NULL));

    do {
        pick = list[rand() % size];
    } while(!taken[pick]);

    return pick;
}







bool find_players(int size, const int *list) {

    bool found = false;
    int u;
    for(u = 0; u < size; u++) {

        if(list[u] < 0) {
            found = true;
        }
    }

    return found;
}


int form(int num) {

    int ret;

    if(num >= 0) {
        ret = -(num + 1);
    } else {
        ret = -num - 1;
    }

    return ret;
}



bool is_numeric(char c) {

    if((int)c >= 48 && (int)c <= 57) {
        return true;
    } else {
        return false;
    }
}