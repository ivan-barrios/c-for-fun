#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    unsigned num : 4;
    char palo[10];
}Carta;



void inicializarMazo(Carta mazo[]);
void imprimirMazo(Carta mazo[]);
void barajar(Carta mazo[]);

int main()
{
    Carta mazo[48];
    inicializarMazo(mazo);
    barajar(mazo);
    imprimirMazo(mazo);



    return 0;
}

void inicializarMazo(Carta mazo[]) {
    int i,j;
    char palos[4][10] = {{"Oro"}, {"Espada"}, {"Copa"}, {"Basto"}};
    for (i = 0; i < 4; i++){
        for (j = 1; j <= 12; j++){
            mazo[12 * i + j - 1].num = j;
            strcpy(mazo[12 * i + j - 1].palo, palos[i]);
        }
    }
}

void imprimirMazo(Carta mazo[]) {
    for (int i = 0; i<48; i++) {
        printf("Palo: %s  ", mazo[i].palo);
        printf("Numero: %u  ", mazo[i].num);
    }
}

void barajar(Carta mazo[]) {
    srand(time(NULL));
    Carta actual;
    for (int i=0; i<48; i++) {
        actual = mazo[i];
        int n = rand() % 48 + 1;
        mazo[i] = mazo[n];
        mazo[n] = actual;
    }
}
