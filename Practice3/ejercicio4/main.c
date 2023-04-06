#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void imprimirMazo(Card [], int);
void mix(Card []);

int main()
{
    Card mazo[MAZO];
    inicializarMazo(mazo, NUMEROS, PALOS);
    imprimirMazo(mazo, MAZO);
    mix(mazo);
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
void imprimirMazo(Card mazo[], int cantCartas) {
    int i;
    for (i = 0; i < cantCartas; i++) {
        printf("%d ", mazo[i].num);
        printf("%s ", mazo[i].palo);
    }
}

void mix(Card mazo[]) {
    //mix mazo
}
