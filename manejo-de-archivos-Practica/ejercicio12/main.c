#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int id;
    unsigned int dni;
    unsigned int desplazamiento;
    char apellido[40];
    char nombre[40];
    char trabajo[40];
    char correo[40];
    char ciudad[40];
    char pais[40];
} Persona;

struct nodo{
    Persona dato;
    struct nodo *sig;
};
typedef struct nodo Nodo;

//Prototipos
void inicializarLista(Nodo **);
void insertarOrdenado(Nodo **l, Persona p);
void liberar(Nodo ** lista);
void imprimirArchivoBinario();

/*----------------------------------------------------------------------------------*/

int main()
{
    //Abro archivo con errorHandler
    FILE *f = fopen("personas.csv", "r");
    if(f == NULL) {
        printf("No se pudo abrir el archivo personas.csv");
        return 1;
    }

    char campos[400];
    fgets(campos, 400, f); //Agarro primera linea de campos

    //Inserto ordenadamente por dni en la lista a cada uno de los datos
    Persona p;
    Nodo *lista;
    inicializarLista(&lista);

    while(!feof(f)) {
        p.desplazamiento = ftell(f);
        fscanf(f, "%u;%u;%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
               &p.id, &p.dni, p.apellido, p.nombre, p.trabajo, p.correo, p.ciudad, p.pais);
        insertarOrdenado(&lista, p);
    }
    fclose(f);


    FILE *bf = fopen("personas.idx", "wb");
    if(bf == NULL) {
        printf("No se pudo crear el archivo personas.idx");
        return 1;
    }

    Nodo *aux = lista;

    while (aux != NULL) {
        fwrite(&aux->dato.dni, sizeof(unsigned int), 1, bf);
        fwrite(&aux->dato.desplazamiento, sizeof(unsigned int), 1, bf);
        aux = aux->sig;
    }

    fclose(bf);

    liberar(&lista);
    liberar(&aux);

    imprimirArchivoBinario();

    printf("Litoo");

    return 0;
}

/*----------------------------------------------------------------------------------*/

void inicializarLista(Nodo **lista) {
    *lista = NULL;
}

void insertarOrdenado(Nodo **l, Persona p) {
    Nodo *nuevo, *ant, *act;
    ant = *l;
    act = *l;
    nuevo = malloc(sizeof(Nodo));
    nuevo->dato = p;
    while((act!=NULL) && (act->dato.dni < p.dni)) {
        ant = act;
        act = act->sig;
    }

    nuevo->sig = act;
    if (ant == act){
        *l = nuevo;
    }
    else
        ant->sig = nuevo;

}

void liberar(Nodo ** lista) {
    Nodo *aux;
    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->sig;
        free(aux);
    }
}

void imprimirArchivoBinario() {

    FILE *f = fopen("personas.idx", "rb");
    unsigned int dni;
    unsigned int desp;

    fread(&dni, sizeof(unsigned int), 1, f);
    fread(&desp, sizeof(unsigned int), 1, f);
    while(!feof(f)) {
        printf("%u     %u\n", dni, desp);
        fread(&dni, sizeof(unsigned int), 1, f);
        fread(&desp, sizeof(unsigned int), 1, f);
    }

    fclose(f);
}


