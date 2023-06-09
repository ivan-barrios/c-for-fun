#include <stdio.h>
#include <stdlib.h>

void mostrarMatriz(const int [][4]);
void matrizTranspuesta(const int [][4]);

int main()
{
    int arr[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    mostrarMatriz(arr);
    printf("\n");
    matrizTranspuesta(arr);


    return 0;
}

void mostrarMatriz(const int arr[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d   ", arr[i][j]);
        }
        printf("\n");
    }
}

void matrizTranspuesta(const int arr[][4]) {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d   ", arr[j][i]);
        }
        printf("\n");
    }

}
