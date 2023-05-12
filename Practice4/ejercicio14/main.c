//Escriba un programa que lea desde teclado un valor entero n y reserve memoria para una matriz
//triangular inferior de orden n de enteros. Como se desea ahorrar espacio de almacenamiento, no se
//deben almacenar los elementos cuyo valor es 0, es decir, s�lo se reservar� memoria para los valores
//del tri�ngulo inferior de la matriz. Luego, inicialice la estructura con valores aleatorios entre 0 y 20
//e impr�mala en pantalla. Por �ltimo, libere la memoria reservada.
//Nota: modularice la reserva de memoria, la inicializaci�n, la impresi�n y la liberaci�n de memoria.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *reservar(int n) {
    //De una matriz cuadrada, tengo la mitad + n elementos si
    //es una matriz inferior.
    int *matrix = calloc((((n*n)+n))/2, sizeof(int));
    return matrix;
}

void inicializarAleatorio(int *matrix, int n){
    int cantElem = ((n*n)+n)/ 2;
    for (int i=0; i < cantElem; i++){
        matrix[i] = rand() % 20;
    }
}

void imprimirInf(int *matrix, int n) {
    int cantElem = ((n*n)+n)/ 2;
    int processed = 1;

    for(int j=0; j<n; j++, processed++){
        //Imprimo los que tenga que imprimir
        for(int k=0; k<processed; k++) {
            //printf(" %d -", 1);
            printf(" %2d -", matrix[j]);
            cantElem--;
        }
        //Imprimo el resto (ceros)
        for(int w=0; w<(n-processed); w++) {
            printf(" %2d -", 0);
        }
        printf("\n");
    }

}


int main()
{
    srand(time(NULL));
    int n;
    printf("Ingresa n: ");
    scanf("%d", &n);
    int *matrix = reservar(n);
    inicializarAleatorio(matrix, n);
    imprimirInf(matrix, n);


    return 0;
}
