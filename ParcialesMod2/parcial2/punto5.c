#include <stdio.h>
#include <stdlib.h>

int main() {
    char *nomArch;
    printf("Ingrese el nombre del archivo para leer: ");
    scanf("%s", nomArch);

    FILE *tarch = fopen(nomArch, "r");
    if (tarch == NULL) {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    char c;
    printf("Ingrese el caracter a buscar: ");
    scanf(" %c", &c);

    printf("Nombre del archivo binario: ");
    scanf("%s", nomArch);
    FILE *barch = fopen(nomArch, "wb");
    if (barch == NULL) {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    int pos;
    char cAux;
    cAux = fgetc(tarch);
    while (!feof(tarch)){
        if(cAux == c){
            printf("Posicion: %d\n", ftell(tarch));
            pos = ftell(tarch);
            fwrite(&pos, sizeof(int), 1, barch);
        }
        cAux = fgetc(tarch);
    }
    fclose(tarch);
    fclose(barch);
    return 0;
}