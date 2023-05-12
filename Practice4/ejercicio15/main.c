//15. Escriba un programa que, dado un n�mero entero n ingresado por
//teclado, construya una pir�mide de pascal de n filas. Un tri�ngulo de
//pascal es una serie de filas apiladas que comienza con un elemento y
//agrega un elemento m�s en cada fila. El primer y �ltimo elemento de
//cada fila es un 1. Los dem�s elementos se calculan sumando los 2
//n�meros superiores de la fila anterior. Por ejemplo, para obtener el
//segundo elemento de la cuarta fila (4) deben sumarse el primer (1) y
//segundo (3) elemento de la tercera fila de forma que 1+3 = 4. Tenga en
//cuenta las siguientes condiciones:
//a) Utilizar una estructura de datos eficiente. Contemple la informaci�n necesaria para recorrer
//la pir�mide y liberar la memoria de forma correcta.
//b) Implemente una funci�n que dado un entero n retorne una pir�mide de pascal de n filas.
//c) Implemente una funci�n para imprimir la pir�mide.
//d) Implemente una funci�n para destruir la pir�mide.


#include <stdio.h>
#include <stdlib.h>

int ** reservarPiramide(int n) {
    int ** piramide;
    int i,j;

    for(i=0; i<n; i++) {
        piramide = calloc(n, sizeof(int *));
    }
    for(j=0; j<n; j++) {
        piramide[j] = calloc((j+1), sizeof(int));
    }
    return piramide;
}

void cargarPascal(int **piramide, int n) {

    int i,j;

    for(i=0; i < n; i++) {
        for(j=0; j < i+1; j++) {
            if(j == 0 || j == i) {
                piramide[i][j] = 1;
            }
            else {
                piramide[i][j] = piramide[i-1][j] + piramide[i-1][j-1];
            }
        }
    }
}

void imprimirPiramide(int **piramide, int n) {
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<i+1; j++) {
            printf("  %2d  ", piramide[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    int n;
    printf("Ingrese n: ");
    scanf("%d", &n);

    int **piramide = reservarPiramide(n);

    cargarPascal(piramide, n);

    imprimirPiramide(piramide, n);


    //Libero memoria
    for(int i=0; i<n; i++){
        free(piramide[i]);
    }
    free(piramide);

    return 0;
}
