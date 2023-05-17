/*
Escriba un programa que permita a un usuario consultar si un conjunto de palabras existe o no en
un diccionario. El usuario ingresa de a una palabra y la consulta finaliza cuando ingresa la palabra
“ZZZ”. Para cada palabra ingresada se debe informar si la misma pertenece o no al diccionario.
El diccionario consiste en un archivo de texto y las palabras se encuentran ordenadas en forma
ascendente (una por línea). Se desea generar una estructura de datos dinámica (memoria RAM) en
la cual se almacenen las palabras de todo el diccionario. Luego, verifique la pertenencia de las
palabras ingresadas por el usuario utilizando dicha estructura en lugar del archivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLONG 50

void agregarPalabra(char **diccionario, char *palabra, int cantPalabras) {
    //Esta funcion rompe el ejercicio
    char ** aux = diccionario;
    aux = realloc(aux, cantPalabras);
    aux[cantPalabras-1] = palabra;
    printf("%s", aux[0]);
}

void printDiccionario(char **diccionario, int cantPalabras) {
    int i;
    for (i=0; i<cantPalabras; i++) {
        printf("%s", diccionario[i]);
    }
}


int main()
{
    FILE *arch = fopen("diccionario.txt", "r");
    if (!arch) {
        printf("Error al abrir el diccionario");
        return 1;
    }

    //Guardo en estructura dinamica mi diccionario
    char **diccionario;
    char palabra[MAXLONG];
    int cantPalabras = 0;
    fgets(palabra, MAXLONG, arch);
    while(!feof(arch)) {
        cantPalabras++;
        agregarPalabra(diccionario, palabra, cantPalabras);
        fgets(palabra, MAXLONG, arch);
    }
    //printDiccionario(diccionario, cantPalabras);

    fclose(arch);

    return 0;
}
