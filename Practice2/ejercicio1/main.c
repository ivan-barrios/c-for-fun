#include <stdio.h>
#include <stdlib.h>
#define DIMF 50

int paresEnImpares(const int [], int);
int imparesEnPares(const int [], int);

int main()
{
    int arr[DIMF], i;

    for (i = 0; i < DIMF; i++) {
        arr[i] = rand();
        printf("%d \n", arr[i]);
    }

    printf("Hay %d numeros pares en las posiciones impares. \n", paresEnImpares(arr, DIMF));

    printf("Hay %d numeros impares en las posiciones pares. \n", imparesEnPares(arr, DIMF));

    return 0;
}

int paresEnImpares(const int arr[], int longitud) {
    int cant;

    for (int i = 1; i < longitud; i += 2) {
        if (!(arr[i] % 2)) {
            cant++;
        }
    }

    return cant;

}


int imparesEnPares(const int arr[], int longitud) {
    int cant;

    for (int i = 0; i < longitud; i += 2) {
        if (arr[i] % 2) {
            cant++;
        }
    }

    return cant;

}
