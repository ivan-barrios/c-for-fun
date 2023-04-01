#include <stdio.h>
#include <stdlib.h>

int swap(int);

int main()
{ int x;

    printf("Ingrese el numero que desea invertir: ");
    scanf(" %d", &x);

    printf("El numero invertido es: %d \n", swap(x));

    return 0;
}

int swap(int num) {
    int aux, resultado;

    while (num != 0) {
        aux = num % 10;
        resultado = (resultado * 10) + aux;
        num /= 10;
    }

    return resultado;

}
