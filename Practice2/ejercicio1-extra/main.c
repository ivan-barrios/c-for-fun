#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIMF 20

void inicializacion(int [], int);
void imprimir(int [], int);
void ordenar(int [], int);
void swap(int *, int*);

int main()
{
    int vec[DIMF];
    srand(time(NULL));
    inicializacion(vec, DIMF);
    imprimir(vec, DIMF);
    ordenar(vec, DIMF);
    printf("\n");
    imprimir(vec, DIMF);

    return 0;
}

void inicializacion(int vec[], int dimf) {
    int i;
    for (i = 0; i < dimf; i++) {
        vec[i] = (rand() % 100) + 1;
    }
}
void imprimir(int vec[], int dimf) {
    int i;
    for (i = 0; i < dimf; i++) {
        printf("%d ", vec[i]);
    }
}
void ordenar(int vec[], int dimf) {
    int i, j;
    for (i = 0; i < dimf; i++) {
        for (j = i; j < dimf; j++) {
            if (vec[i] > vec[j]) {
                int tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
            }
        }
    }
}
