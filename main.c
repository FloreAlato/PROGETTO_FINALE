


#include "games.h"



void scrematura(int, const int*, bool*);



bool check = true;
bool now = true;
bool choice = false;
int num;

int i;

char saves_menu[] = "saves_collection.txt";
char name[64];
char si_o_no[2][10] = {"no", "si"};









int main() {

    //TESTING
    int p[2] = {-1, -3};
    int r = morra_cinese(p);
    printf("\n%d\n", p[r]);

    //srand(time(NULL));



    //inserire profilo giocatore

    ProfiloGiocatore *players = NULL;

    int numero_giocatori = 1, n = 0;



    choice = choice_string("\nVuoi inserire un profilo giocatore? (si/no)\n[Tu]: ", &si_o_no[0]);

    if(choice) {
        players = (ProfiloGiocatore *)calloc(numero_giocatori, sizeof(ProfiloGiocatore));

        if(players == NULL) {
            printf("\n\n\nALLOCAZIONE DI 'players' FALLITA!!\n\n\n");
            exit(-1);
        }
    }

    do {
        n++;

        printf("\nNome: ");
        scanf("%s", name);
        getchar();

        strcpy(players[n].nome, name);

        choice = choice_string("\nVuoi inserire un altro profilo? (si/no)\n[Tu]: ", &si_o_no[0]);

        if(choice) {
            numero_giocatori++;

            realloc(players, numero_giocatori * sizeof(ProfiloGiocatore));

            if(players == NULL) {
                printf("\n\n\nREALLOCAZIONE DI 'players' FALLITA!!\n\n\n");
                exit(-1);
            }
        }

    } while(choice);



    for(int c = 0; c <= n; c++) {
        printf("\n%s", players[c].nome);
    }



    free(players);


    //questa parte permette di inserire i profili giocatore
    //ma e' gestita con un booleano, quindi per adattare al resto delle opzioni bisogna ricevere input intero
    //non ho ancora una funzione per quello














    /*INPUT GIOCATORE, PROVVISORIO

    int size = get_int("\nNumero giocatori: ", 16, 999);
    int *players = NULL;
    bool *alive = NULL;

    players = (int *)calloc(size, sizeof(int));
    alive = (bool *)calloc(size, sizeof(bool));

    if(players == NULL || alive == NULL) {
        exit(-1);
    }

    for(int d = 0; d < size; d++) {
        players[d] = d;
        alive[d] = true;
    }


    for(int j = 0; j < size; j++) {
        printf("\n%s", print_player(players[j]));
        if(alive[j] == true) {
            printf(" (vivo)");
        } else {
            printf(" (morto)");
        }
    }

    //FINE INPUT GIOCATORE*/



    return 0;
}








void scrematura(int n, const int *players, bool *alive) {

    int num = 2;
    while(num <= n) {
        num *= 2;
    }
    num /= 4;

    printf("\nNe servono di meno... facciamo %d?\n", num);

    //fare gruppi per scremare
    //far giocare i gruppi e prendere i giocatori
    //aggiornare la lista con i giocatori in vita e quelli morti

    for(int f = num; f < n; f++) {
        alive[f] = false;
    }
}