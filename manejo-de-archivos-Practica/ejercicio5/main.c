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

struct structNodo {
    char dato[MAXLONG];
    struct structNodo *next;
};
typedef struct structNodo Nodo;


void agregarPalabra(Nodo **listaDiccionario, char *palabra) {
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    if (nuevo != NULL) { //Hay espacio para el nodo
        strcpy(nuevo->dato, palabra);
        nuevo->next = NULL;
        if (*listaDiccionario == NULL) *listaDiccionario = nuevo;
        else {
            Nodo *aux = *listaDiccionario;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = nuevo;
        }
    }
}

int buscarEnDic(Nodo *listaDiccionario, char *palabra) {
    int exito = 1;
    while ((listaDiccionario != NULL) && exito ) {
        exito = strcmp(listaDiccionario->dato, palabra);
        listaDiccionario = listaDiccionario->next;
    }
    return !exito;
}



/*
void printDiccionario(Nodo *listaDiccionario) {
    while (listaDiccionario != NULL) {
        printf("%s -> ", listaDiccionario->dato);
        listaDiccionario = listaDiccionario->next;
    }
    printf("NULL");
}
*/


int main()
{
    FILE *arch = fopen("diccionario.txt", "r");
    if (!arch) {
        printf("Error al abrir el diccionario");
        return 1;
    }

    //Guardo en estructura dinamica mi diccionario
    Nodo *listaDiccionario = NULL;
    char palabra[MAXLONG];
    fscanf(arch, "%s\n", palabra);
    while(!feof(arch)) {
        agregarPalabra(&listaDiccionario, palabra);
        fscanf(arch, "%s\n", palabra);
    }
    agregarPalabra(&listaDiccionario, palabra); //Podria mejorar esto?
    fclose(arch);

    printf("Ingrese palabra: ");
    scanf("%s", palabra);
    while(strcmp(palabra, "ZZZ")) {
        if (buscarEnDic(listaDiccionario, palabra)) printf("La palabra ESTA en el diccionario \n");
        else printf("La palabra NO ESTA en el diccionario \n");
        printf("Ingrese palabra: ");
        scanf("%s", palabra);
    }

    return 0;
}
