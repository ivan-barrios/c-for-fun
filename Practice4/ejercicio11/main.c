#include <stdio.h>
#include <stdlib.h>


int ** reservarMatriz(int, int);

void cargarMatriz(int **, int, int);

void printMatrix(int **, int, int);

void printMultThree(int **, int, int);

void freeMatrixMem(int **, int);

int main()
{
    int n,m;
    printf("Ingrese numero de filas");
    scanf("%d", &n);
    printf("Ingrese numero de columnas");
    scanf("%d", &m);

    int ** matrix = reservarMatriz(n, m);
    cargarMatriz(matrix, n, m);
    printMatrix(matrix, n, m);
    printMultThree(matrix, n, m);
    freeMatrixMem(matrix, n);


    return 0;
}

int ** reservarMatriz(int filas, int columnas) {
    int ** aux;
    int f;
    aux = malloc(filas * (sizeof(int *)));
    for (f = 0; f < filas; f++) {
        aux[f] = malloc(columnas * sizeof(int));
    }
    return aux;
}


void cargarMatriz(int ** matrix, int filas, int columnas) {
    int f, c;

    for (f = 0; f < filas; f++) {
        for (c = 0; c < columnas; c++) {
            printf("Ingrese un numero: ");
            scanf("%d", &(matrix[f][c]));
        }
    }
}

void printMultThree(int **matrix, int rows, int cols) {
    int f, c;
    for (f=0; f<rows; f++){
        for(c=0; c<cols; c++){
            if(!(matrix[f][c] % 3)) {
                printf("%d es multiplo del tres \n", matrix[f][c]);
            }
        }
    }
}

void freeMatrixMem(int **matrix, int rows) {
    int f;
    for (f=0; f<rows; f++) {
        free(matrix[f]);
    }
    free(matrix);
}



void printMatrix(int ** matrix, int rows, int cols) {
    int f, c;
    for (f=0; f<rows; f++){
        for(c=0; c<cols; c++){
            printf("    %d   ",matrix[f][c]);
        }
        printf("\n");
    }
}

