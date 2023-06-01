#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED
#define MAX_LENGTH 100

struct nodo{
    char palabra[MAX_LENGTH];
    struct nodo * sig;
};
typedef struct nodo Nodo;
typedef Nodo *Lista;

Lista crearDiccionario(); //Crea un diccionario vacio

int agregarPalabra(Lista* l, char *p); //Agrega p en l y retorna si agrego o no

int existePalabra(Lista l, char *p); //Determina si p esta o no en l

int eliminarPalabra(Lista* l, char *p); //Elimina p de l y retorna si elimino o no

void cargarDesdeArchivo(Lista* l, char * nArch); //Carga las palabras del archivo con nombre nArch en l

void guardarEnArchivo(Lista l, char * nArch); //Carga en el archivo de nombre nArch los elementos de la lista

void destruir(Lista* l); //Libera todos los datos de la lista

#endif // DICCIONARIO_H_INCLUDED
