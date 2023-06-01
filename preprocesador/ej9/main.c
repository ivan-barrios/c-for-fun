#include <stdio.h>
#include <stdlib.h>
#include "imath.h"




int main()
{
    int n;

    printf("Ingrese un numero: ");
    scanf("%d", &n);
    while(n != 0) {
        if (par(n)) {
            printf("Cuadrado: %d\n",cuadrado(n));
            printf("Cubo: %d\n",cubo(n));
        }
        else {
            printf("Factorial: %d\n", factorial(n));
        }
        printf("Ingrese un numero: ");
        scanf("%d", &n);
    }

    return 0;
}
