#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define PALOLONG 10
#define NUMEROS 12
#define PALOS 4
#define COMODINES 2
#define MAZO NUMEROS*PALOS+COMODINES

const char palos[PALOS][PALOLONG] = {"Oro", "Copa", "Espada", "Basto"};
const int numeros[NUMEROS] = {1,2,3,4,5,6,7,8,9,10,11,12};

struct CardStruct {
    char palo[PALOLONG];
    int num;
};
typedef struct CardStruct Card;




void inicializarMazo(Card [], int, int);
void imprimirMazo(const Card [], int);
void mix(Card [], int);
void swap(Card *, Card *, int);
Card sacarCarta(Card [], int, int);
void devolverCarta(Card [], Card, int, int);



int main()
{   srand(time(NULL));
    Card mazo[MAZO];
    inicializarMazo(mazo, NUMEROS, PALOS);
    imprimirMazo(mazo, MAZO);
    //mix(mazo, PALOLONG);
    printf(" \n");
    //imprimirMazo(mazo, MAZO);
    Card carta = sacarCarta(mazo, 11, MAZO);
    imprimirMazo(mazo, MAZO);
    devolverCarta(mazo, carta, 11, MAZO);
    imprimirMazo(mazo, MAZO);
    return 0;
}




void inicializarMazo(Card mazo[], int cantNumeros, int cantPalos) {
    int i, j;
    for (i = 0; i < cantPalos; i++) {
        for (j = 0; j < cantNumeros; j++){
            strcpy(mazo[cantNumeros*i+j].palo, palos[i]);
            mazo[cantNumeros*i+j].num = numeros[j];
        }
    }
    mazo[48].num = 999;
    strcpy(mazo[48].palo, "Comodin");
    mazo[49].num = 999;
    strcpy(mazo[49].palo, "Comodin");
}
void imprimirMazo(const Card mazo[], int cantCartas) {
    int i;
    for (i = 0; i < cantCartas; i++) {
        printf("%d ", mazo[i].num);
        printf("%s ", mazo[i].palo);
    }
}



void mix(Card mazo[], int paloLongitud) {
    for (int i = 0; i < 30; i++) {
        swap(&mazo[rand() % 50], &mazo[rand() % 50], paloLongitud);
    }
}
void swap(Card *a, Card *b, int paloLongitud) {
    int numTmp = (*a).num;
    char paloTmp[paloLongitud];
    strcpy(paloTmp, (*a).palo);

    (*a).num = (*b).num;
    strcpy((*a).palo, (*b).palo);

    (*b).num = numTmp;
    strcpy((*b).palo, paloTmp);
}



Card sacarCarta(Card mazo[], int posASacar, int cantCartas) {
    Card carta = mazo[posASacar];
    int i;
    for (i = posASacar; i < cantCartas - 1; i++) {
        mazo[i].num = mazo[i + 1].num;
        strcpy(mazo[i].palo, mazo[i + 1].palo);
    }
    mazo[i].num = 0;
    strcpy(mazo[i].palo, "Vacio");
    return carta;
}

void devolverCarta(Card mazo[], Card cartaADevolver, int posADevolver, int cantCartas) {
    int i;
    for (i = cantCartas; i > posADevolver; i--) {
        mazo[i].num = mazo[i-1].num;
        strcpy(mazo[i].palo, mazo[i - 1].palo);
    }
    mazo[posADevolver].num = cartaADevolver.num;
    strcpy(mazo[posADevolver].palo, cartaADevolver.palo);
}

