#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define JUGADORES 3

typedef struct {
    char nombre[20];
    char apellido[20];
    unsigned int edad;
    unsigned int cantTitulos;
    unsigned int ranking;
    int fortune;
} Jugador;

void leerYGuardar(FILE **bf, int cant);

void informarDatos(FILE **f, int cant);

void imprimirDatos(FILE **f, int cant);


//En el archivo voy a tener char, unsigned, unsigned, unsigned, int
int main()
{
    FILE *bf = fopen("data", "wb");
    if (bf == NULL) {
        printf("Hubo un error al crear el archivo binario");
        return 1;
    }

    leerYGuardar(&bf, JUGADORES);

    fclose(bf);

    FILE *barch = fopen("data", "rb");
    if (barch == NULL) {
        printf("Hubo un error al abrir el archivo binario");
        return 1;
    }

    informarDatos(&bf, JUGADORES);

    fclose(barch);

    return 0;
}



void leerYGuardar(FILE **bf, int cant){
    Jugador j;
    int i;

    for(i=0; i<cant; i++) {
        printf("Nombre: ");
        scanf("%s", j.nombre);
        fwrite(j.nombre, sizeof(char), 20, *bf);
        printf("Apellido: ");
        scanf("%s", j.apellido);
        fwrite(j.apellido, sizeof(char), 20, *bf);
        printf("Edad: ");
        scanf("%u", &j.edad);
        fwrite(&j.edad, sizeof(unsigned int), 1, *bf);
        printf("Cantidad de Titulos: ");
        scanf("%u", &j.cantTitulos);
        fwrite(&j.cantTitulos, sizeof(unsigned int), 1, *bf);
        printf("Ranking actual: ");
        scanf("%u", &j.ranking);
        fwrite(&j.ranking, sizeof(unsigned int), 1, *bf);
        printf("Fortuna acumulada: ");
        scanf("%d", &j.fortune);
        fwrite(&j.fortune, sizeof(int), 1, *bf);
    }
    printf("Successful reading \n");
}


void informarDatos(FILE **f, int cant) {
    unsigned int bestRank = 10000, maxTitulos = 0;
    char rankNom[20], rankAp[20];
    char titulosNom[20], titulosAp[20];
    Jugador j;
    for (int i = 0; i < cant; i++) {
        fread(j.nombre, sizeof(char), 20, *f);
        fread(j.apellido, sizeof(char), 20, *f);
        fread(&j.edad, sizeof(unsigned int), 1, *f);
        fread(&j.cantTitulos, sizeof(unsigned int), 1, *f);
        fread(&j.ranking, sizeof(unsigned int), 1, *f);
        fread(&j.fortune, sizeof(unsigned int), 1, *f);
        if (bestRank > j.ranking) {
            bestRank = j.ranking;
            strcpy(rankNom, j.nombre);
            strcpy(rankAp, j.apellido);
        }
        if (maxTitulos < j.cantTitulos) {
            maxTitulos = j.cantTitulos;
            strcpy(titulosNom, j.nombre);
            strcpy(titulosAp, j.apellido);
        }
    }
    printf("El jugador con mejor ranking es: %s %s \n", rankNom, rankAp);
    printf("EL jugador con mas titulos es: %s %s \n", titulosNom, titulosAp);
}



void imprimirDatos(FILE **f, int cant) {
    Jugador j;
    for (int i = 0; i < cant; i++) {
        fread(j.nombre, sizeof(char), 20, *f);
        printf("%s, ", j.nombre);
        fread(j.apellido, sizeof(char), 20, *f);
        printf("%s, ", j.apellido);
        fread(&j.edad, sizeof(unsigned int), 1, *f);
        printf("%u, ", j.edad);
        fread(&j.cantTitulos, sizeof(unsigned int), 1, *f);
        printf("%u, ", j.cantTitulos);
        fread(&j.ranking, sizeof(unsigned int), 1, *f);
        printf("%u, ", j.ranking);
        fread(&j.fortune, sizeof(int), 1, *f);
        printf("%d\n", j.fortune);
    }
}
