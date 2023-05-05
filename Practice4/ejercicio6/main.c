#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo *sig;
};
typedef struct nodo Nodo;


void inicializar(Nodo **);

void eliminarTodo(Nodo **);

void agregarAlInicio(Nodo **, int);

void agregarAlFinal(Nodo **, int);

int cantElementos(Nodo *lista);

void imprimirLista(Nodo *);



int main()
{
    Nodo *lista;
    inicializar(&lista);
    agregarAlFinal(&lista, 4);
    agregarAlInicio(&lista, 5);
    agregarAlFinal(&lista, 6);
    imprimirLista(lista);
    printf("%d", cantElementos(lista));
    //eliminarTodo(&lista);
    //imprimirLista(lista);

    return 0;
}

void inicializar(Nodo **lista) {
    *lista = NULL;
}

void eliminarTodo(Nodo ** lista) {
    Nodo *aux;
    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->sig;
        free(aux);
    }
}

void agregarAlInicio(Nodo **lista, int num) {
    Nodo *aux = (Nodo *) malloc(sizeof(Nodo));
    aux->dato = num;
    aux->sig = *lista;
    *lista = aux;
}

void agregarAlFinal(Nodo **lista, int num) {
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    nuevo->dato = num;
    nuevo->sig = NULL;

    if (*lista == NULL) {
        *lista = nuevo;
    }
    else {
        Nodo *aux = *lista;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

}

int cantElementos(Nodo *lista) {
    int cont = 0;
    while (lista != NULL) {
        cont++;
        lista = lista->sig;
    }
    return cont;
}

void imprimirLista(Nodo *lista) {

    while(lista != NULL) {
        printf("%d -> ", lista->dato);
        lista = lista->sig;
    }
    printf("NULL \n");
}
