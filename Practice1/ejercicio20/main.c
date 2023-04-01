#include <stdio.h>
#include <stdlib.h>

int damePar();

int main()
{
    int n, i;

    printf("Ingrese la cantidad de numeros pares que quiere: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("%d \n", damePar());
    }

    return 0;
}

int damePar() {
    static int num = -2;
    num += 2;
    return num;
}
