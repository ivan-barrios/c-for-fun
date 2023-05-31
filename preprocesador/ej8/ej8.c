/*
Realice un programa que genere un vector de 1000 enteros al azar y utilice una función para localizar un
elemento. Se pide:
a) Implementar la función de búsqueda que, dado un entero, retorne la posición donde se encuentra.
En caso de no existir el número retorne -1.
b) Modificar a) para agregar información de depuración que permita imprimir en consola la cantidad
de veces que se debió acceder al arreglo para encontrar (o no) el elemento en cada llamado a la
función. Utilice las directivas del procesador para activar/desactivar la depuración e imprimir/no
imprimir la información en la consola.
c) Verifique el tamaño del programa compilando con la depuración y sin la depuración. Explique
porque difieren.
*/  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG 1
#define LONG 10


int localizar(int v[], int cant, int n);

int main()
{
    srand(time(NULL)); //seed para generar numeros aleatorios

    int vector[LONG];
    for (int i = 0; i < LONG; i++)
    {
        vector[i] = rand() % LONG;
    }

    int n;
    printf("Ingrese un numero a buscar: ");
    scanf("%d", &n);
    printf("%d", localizar(vector, LONG, n));


    return 0;
}

int localizar(int v[], int cant, int n) {
    int pos = -1;
    int i;
    for (i = 0; i < cant; i++)
    {
        if (v[i] == n)
        {
            pos = i;
            break;
        }
    }
    #ifdef DEBUG
        printf("Se accedio %d veces al arreglo", i);
    #endif
    return pos;
}