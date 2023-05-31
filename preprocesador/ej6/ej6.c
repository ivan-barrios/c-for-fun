/*
Realice un programa que defina una macro AREA_CIRCULO(r) que permita calcular el área de un círculo
para un radio r. El cuerpo del programa debe generar aleatoriamente 10 valores diferentes que
representan radios e imprimir el área correspondiente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.141592
#define AREA_CIRCULO(r) (PI * (r) * (r))


int main(int argc, char const *argv[])
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int radio = rand() % 100;
        printf("Radio: %d\tArea: %f\n", radio, AREA_CIRCULO(radio));
    }

    return 0;
}
