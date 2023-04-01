#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLONG 20

int main()
{
    char fin[4] = "XXX";
    char cadena[MAXLONG];
    int cant = 0, longitud;

    printf("Para finalizar ingrese: XXX \n");

    printf("Ingrese una palabra: ");

    scanf("%s", cadena);

    while (strcmp(cadena, fin)) {
        longitud = strlen(cadena);
        if (cadena[longitud - 1] == 'o') cant++;
        printf("Ingrese otra palabra: ");
        scanf("%s", cadena);
    }

    printf("La cantidad de palabras que terminan con o es: %d", cant);


    return 0;
}
