/*
Escriba un programa que copie el contenido de un archivo de texto en otro nuevo.
a) Utilizando las funciones fgetc y fputc. <------------------------------------
b) Utilizando las funciones fgets y fputs.
c) Utilizando las funciones fread y fwrite
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 500

int main()
{
    //VERSION A)
    /*
    //Abro y creo archivos a copiar y pegar
    FILE *arch, *copia;
    arch = fopen("archivoFuente.txt", "r");
    copia = fopen("archivoCopia.txt", "w");
    if ((arch == NULL) || (copia == NULL)) {
        printf("No se pudo abrir/crear el archivo fuente/copia");
        return 1;
    }

    //Variables auxiliares
    int c;

    //Voy copiando mientras leo
    c = fgetc(arch);
    while (!feof(arch)) {
        fputc(c, copia);
        c = fgetc(arch);
    }

    printf("Successful copy");

    //Cierro archivos
    fclose(arch);
    fclose(copia);

    return 0;
    */

    //VERSION B
    /*
    FILE *arch, *copia;
    arch = fopen("archivoFuente.txt", "r");
    copia = fopen("archivoCopia.txt", "w");
    if ((arch == NULL) || (copia == NULL)) {
        printf("No se pudo abrir/crear el archivo fuente/copia");
        return 1;
    }

    //Variables auxiliares
    char line[MAXLEN];

    //Voy copiando mientras leo
    fgets(line, MAXLEN, arch);
    while (!feof(arch)) {
        fputs(line, copia);
        fgets(line, MAXLEN, arch);
    }

    printf("Successful copy");

    //Cierro archivos
    fclose(arch);
    fclose(copia);

    return 0;
    */


    //VERSION C
    FILE *arch = fopen("archivoFuente.txt", "rb");
    FILE *copia = fopen("archivoCopia", "wb");
    if ((arch == NULL) || (copia == NULL)) {
        printf("Hubo un error al abrir o crear archivo");
        return 1;
    }
    char c;

    fread(&c, sizeof(char), 1, arch);
    while (!feof(arch)) {
        fwrite(&c, sizeof(char), 1, copia);
        fread(&c, sizeof(char), 1, arch);
    }

    printf("Successful copy");

    fclose(arch);
    fclose(copia);
}
