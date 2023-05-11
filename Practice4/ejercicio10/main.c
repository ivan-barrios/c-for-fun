#include <stdio.h>
#include <stdlib.h>

double * reservar(int n);
void leerArreglo1(double *arr, int n);
void leerArreglo2(double *arr, int n);

int main()
{
    int n;
    printf("Ingrese tamano del vector: ");
    scanf("%d", &n);


    double *arreglo = reservar(n);
    leerArreglo2(arreglo, n);


    free(arreglo);


    return 0;
}

double * reservar(int n) {
    double *vec = calloc(n, sizeof(double));

    return vec;
}

void leerArreglo1(double *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Ingrese un double: ");
        scanf("%lf", &(arr[i]));
    }
}

void leerArreglo2(double *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Ingrese un double: ");
        scanf("%lf", (arr + i));
    }
}
