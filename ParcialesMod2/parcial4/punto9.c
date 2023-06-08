#include <stdio.h>
#include <stdlib.h>
#include "transformacion.h"

int main(int argc, char * argv[]){
    if (argc <= 2){
        printf("Insuficientes argumentos");
        return 1;
    }

    if (!transformacion(argv[1], argv[2]))
        printf("Transformacion exitosa");
    else 
        printf("No se pudo transformar correctamente");
    
    FILE *arch = fopen("textFile.txt", "r");
    if (!arch){
        printf("No se encontro el archivo textFile.txt");
        return 1;
    }

    char linea[300];

    fgets(linea, 300, arch);
    while (!feof(arch)){
        printf("%s\n", linea);
        fgets(linea, 300, arch);
    }

    fclose(arch);
    
    return 0;
}