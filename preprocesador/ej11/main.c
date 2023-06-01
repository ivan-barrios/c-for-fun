#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diccionario.h"
#define MAX_LENGTH 100



void imprimir(Lista l) {
    while (l != NULL) {
        printf("%s -> ", l->palabra);
        l = l->sig;
    }
    printf("NULL");
}

int main()
{
    char palabra[MAX_LENGTH];
    Lista l = crearDiccionario();
    cargarDesdeArchivo(&l, "savedDictionary.txt");
    printf("Ingrese palabra (jaja = FIN): ");
    scanf("%s", palabra);
    while(strcmp("jaja", palabra)) {
        if (agregarPalabra(&l, palabra) == 0) printf("Ya existe la palabra \n");
        printf("Ingrese palabra (jaja = FIN): ");
        scanf("%s", palabra);
    }


    printf("Ingrese palabra a eliminar (jaja = FIN): ");
    scanf("%s", palabra);
    while(strcmp("jaja", palabra)) {
        if (eliminarPalabra(&l, palabra)) printf("Se elimino exitosamente \n");
        else printf("No existe esa palabra");
        printf("Ingrese palabra (jaja = FIN): ");
        scanf("%s", palabra);
    }


    imprimir(l);

    destruir(&l);

    return 0;
}
