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

int actualizarRanking(char nombre[20], char apellido[20], unsigned int newRank);

void imprimir(int );

int main()
{
    char nom[20];
    char ap[20];
    unsigned int rank;

    printf("Ingrese nombre: ");
    scanf("%s", nom);
    printf("Ingrese apellido: ");
    scanf("%s", ap);
    printf("Nuevo ranking: ");
    scanf("%u", &rank);

    while(strcmp("ZZZ", nom)) {
        if (actualizarRanking(nom, ap, rank))
            printf("Se actualizo correctamente el ranking de %s!\n", nom);
        else
            printf("No se encontro a %s en el archivo, intente nuevamente\n", nom);
        printf("Ingrese nombre: ");
        scanf("%s", nom);
        printf("Ingrese apellido: ");
        scanf("%s", ap);
        printf("Nuevo ranking: ");
        scanf("%u", &rank);
    }

    imprimir(JUGADORES);

    printf("Listoooo!!");

    return 0;
}

int actualizarRanking(char *nombre, char *apellido, unsigned int newRank) {
    FILE *f = fopen("../ejercicio9/data", "rb+");
    Jugador j;
    while(fread(&j, sizeof(Jugador), 1, f) != 0) {
        if(!strcmp(j.nombre, nombre) && !strcmp(j.apellido, apellido)) {
            j.ranking = newRank;
            //Voy a buscar el ultimo que lei (Es el jugador que hay q cambiar)
            //Me tira warning pero me chupa un huevo
            fseek(f, -sizeof(Jugador), SEEK_CUR);
            //Sobreescribe? //SISISISI
            fwrite(&j, sizeof(Jugador), 1, f);
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}


void imprimir(int cant) {

    FILE *f = fopen("../ejercicio9/data", "rb");
    Jugador j;
    for (int i = 0; i< cant; i++) {
        fread(&j, sizeof(Jugador), 1, f);
        printf("Nombre: %s\n Apellido: %s\n Edad: %u\n Titulos: %u\n Rank: %u\n Fortuna: %d\n", j.nombre, j.apellido, j.edad, j.cantTitulos, j.ranking, j.fortune);
    }

    fclose(f);
}
