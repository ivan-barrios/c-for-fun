#include <stdio.h>
#include <stdlib.h>
#define DIMF 3

void mostrarMatriz(int arr[DIMF][DIMF]);

void multiplicacionEscalar(int arr[DIMF][DIMF], int c);

int main()
{
    int arr[DIMF][DIMF] = {{1,2,3}, {4,5,6}, {7,8,9}};

    mostrarMatriz(arr);
    multiplicacionEscalar(arr, -5);
    printf("\n");
    mostrarMatriz(arr);



    return 0;
}

void mostrarMatriz(int arr[DIMF][DIMF]) {
    for (int i = 0; i < DIMF; i++) {
        for (int j = 0; j < DIMF; j++) {
            printf("%d   ", arr[i][j]);
        }
        printf("\n");
    }
}




void multiplicacionEscalar(int arr[DIMF][DIMF], int c) {
    for (int i = 0; i < DIMF; i++) {
        for (int j = 0; j < DIMF; j++) {
            arr[i][j] *= c;
        }
    }
}
