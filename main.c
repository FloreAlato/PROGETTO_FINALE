


#include "dadi.h"



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
    srand(time(NULL));

    int players[2] = {-1, -3};
    int r = dadi(&players[0]);
    printf("\nVince %d", players[r]);





    //operazioni di avvio

    //chiedere se vuole inserire un giocatore o caricare i dati













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