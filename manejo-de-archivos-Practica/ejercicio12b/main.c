#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int id;
    unsigned int dni;
    char apellido[40];
    char nombre[40];
    char trabajo[40];
    char correo[40];
    char ciudad[40];
    char pais[40];
} Persona;

typedef struct {
    unsigned int dni;
    unsigned int desplazamiento;
} Indice;

struct nodo{
    Indice dato;
    struct nodo *sig;
};
typedef struct nodo Nodo;

//Prototipos
void inicializarLista(Nodo **);
void agregarAlFinal(Nodo **, Indice);
void liberar(Nodo ** lista);
int buscar(FILE* personas, Nodo *indice, unsigned dni, Persona * p);

/*----------------------------------------------------------------------------------*/

int main()
{
    //Abro archivo con errorHandler
    FILE *bf = fopen("../ejercicio12/personas.idx", "rb");
    if(bf == NULL) {
        printf("No se pudo abrir el archivo personas.idx");
        return 1;
    }

    //Hago lista de la info de personas.idx
    Indice indice;
    Nodo *lista;
    inicializarLista(&lista);

    while(!feof(bf)) {
        fread(&indice.dni, sizeof(unsigned int), 1, bf);
        fread(&indice.desplazamiento, sizeof(unsigned int), 1, bf);
        agregarAlFinal(&lista, indice);
    }
    fclose(bf);

    FILE *f = fopen("../ejercicio12/personas.csv", "r");

    unsigned int dni;
    Persona p;

    printf("Ingrese el dni de la persona que desea buscar: ");
    scanf("%u", &dni);
    //Proceso hasta que pongan dni = 0
    while (dni != 0) {
        if (buscar(f, lista, dni, &p)) {
            printf("Se encontro!\n");
            printf("ID: %u\nDNI: %u\nApellido: %s\nNombre: %s\nTrabajo: %s\nCorreo: %s\nCiudad: %s\nPais: %s\n",
                   p.id, p.dni, p.apellido, p.nombre, p.trabajo, p.correo, p.ciudad, p.pais);
        }
        else
            printf("No se pudo encontrar la persona asociada al dni ingresado, intente nuevamente\n");
        printf("Ingrese el dni de la persona que desea buscar: ");
        scanf("%u", &dni);
    }

    fclose(f);
    liberar(&lista);

    return 0;
}

/*----------------------------------------------------------------------------------*/

int buscar(FILE* fper, Nodo *indice, unsigned dni, Persona * p) {

    while (indice != NULL) {
        if(dni == indice->dato.dni){
            fseek(fper, indice->dato.desplazamiento, SEEK_SET); //Me paro en la linea que tengo que leer
            fscanf(fper, "%u;%u;%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
                   &p->id, &p->dni, p->apellido, p->nombre, p->trabajo, p->correo, p->ciudad, p->pais);
            return 1;
        }
        indice = indice->sig;
    }
    return 0;
}

void inicializarLista(Nodo **lista) {
    *lista = NULL;
}

void agregarAlFinal(Nodo **lista, Indice indice) {
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    nuevo->dato = indice;
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

void liberar(Nodo ** lista) {
    Nodo *aux;
    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->sig;
        free(aux);
    }
}


