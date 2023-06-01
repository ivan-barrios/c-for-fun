#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diccionario.h"
#define MAX_LENGTH 100


Lista crearDiccionario() {
    Lista l = NULL;
    return l;
}

int agregarPalabra(Lista* l, char *p) {
    //Me fijo si existe o no
    if (existePalabra(*l, p)) {
        return 0;
    }
    //Sino, lo agrego al final
    Nodo * nuevo = (Nodo *) malloc(sizeof(Nodo));
    strcpy(nuevo->palabra, p);
    nuevo->sig = NULL;

    if (*l == NULL) {
        *l = nuevo;
        return 1;
    }
    else {
        Nodo * aux = *l;
        while(aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
        return 1;
    }
}

int existePalabra(Lista l, char *p) {
    while (l != NULL){
        if (!strcmp(l->palabra, p)) {
            return 1;
        }
        l = l->sig;
    }
    return 0;
}

int eliminarPalabra(Lista* l, char *p) {
    Nodo *act = *l, *ant = NULL;
    while (act != NULL) {
        if(!strcmp(act->palabra, p)) {
            if(ant == NULL){
                *l = act->sig;
            }
            else {
                ant->sig = act->sig;
            }
            free(act);
            return 1; //Exito
        }
        ant = act;
        act = act->sig;
    }
    return 0; //Sin exito
}

void cargarDesdeArchivo(Lista* l, char * nArch) {
    FILE *arch = fopen(nArch, "r");
    if(arch == NULL){
        printf("No se pudo abrir el archivo");
        return;
    }
    char p[MAX_LENGTH];
    fscanf(arch, "%s\n", p);
    while (!feof(arch)){
        agregarPalabra(l, p);
        fscanf(arch, "%s\n", p);
    }
    fclose(arch);
}

void guardarEnArchivo(Lista l, char * nArch) {
    FILE* arch = fopen(nArch, "w");
    if(arch == NULL){
        printf("No se pudo abrir el archivo");
        return;
    }
    while (l != NULL){
        fprintf(arch, "%s\n", l->palabra);
        l = l->sig;
    }
    fclose(arch);
}

void destruir(Lista* l) {
    Nodo *act = *l;
    while(act != NULL) {
        Nodo *aux = act;
        act = act->sig;
        free(aux);
    }
}



