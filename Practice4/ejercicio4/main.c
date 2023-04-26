#include <stdio.h>
#include <stdlib.h>

float * reserva(float * pa, int n);       //PREGUNTAR: Tengo que devolver si o si pa (int *)?
void inicializar(float * p, int cant);
float prom(float * p, int cant);


int main()
{
    int n;
    float *pa;
    float promedio;

    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &n);

    pa = reserva(pa, n);
    inicializar(pa, n);
    promedio = prom(pa, n);
    printf(" El Promedio es: %f", promedio);
    free(pa);
    return 0;
}

float * reserva(float * pa, int n) {
    pa = (float *) malloc(sizeof(float)*n);
    return pa;
}

void inicializar(float * p, int cant) {
    int i;
    for (i = 0; i < cant; i++) {
        printf("Ingrese un float: ");
        scanf("%f", &p[i]);
        printf("\n");
    }
}

float prom(float * p, int cant) {
    int i;
    float prom = 0;
    for (i = 0; i < cant; i++) {
        prom += p[i];
    }
    return (prom/cant);
}
