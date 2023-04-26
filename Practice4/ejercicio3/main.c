#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int * reserva(int * pa, int n);       //PREGUNTAR: Tengo que devolver si o si pa (int *)?
void inicializar(int * p, int cant);
int maxNum(int * p, int cant);
void imprimirDatos(int * p, int cant);


int main()
{
    srand(time(NULL));
    int n;
    int *pa;
    int max;

    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &n);

    pa = reserva(pa, n);
    inicializar(pa, n);
    imprimirDatos(pa, n);
    max = maxNum(pa, n);
    printf(" El Mayor Numero es: %d", max);
    return 0;
}

int* reserva(int * pa, int n) {
    pa = (int *) malloc(sizeof(int)*n);
    return pa;
}

void inicializar(int * p, int cant) {
    int i;
    for (i = 0; i < cant; i++) {
        p[i] = (rand() % 1000) - 1;
    }
}

int maxNum(int * p, int cant) {
    int i, max = INT_MIN;
    for (i = 0; i < cant; i++) {
        if (p[i] > max) max = p[i];
    }
    return i != INT_MIN ? max : 0;
}


void imprimirDatos(int * p, int cant) {
    int i;
    for (i = 0; i < cant; i++) {
        printf(" %d ", p[i]);
    }
    printf("\n");
}
