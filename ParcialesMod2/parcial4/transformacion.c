#include <stdio.h>
#include <stdlib.h>
#include "transformacion.h"

int transformacion(char *n1, char *n2) {
    FILE *barch = fopen(n1, "rb");
    if (!barch)
        return 1;
    FILE *tarch = fopen(n2, "w");
    if (!tarch)
        return 2;

    Valoracion v;

    while(fread(&v, sizeof(Valoracion), 1 , barch) == 1){
        fprintf(tarch, "%s | %d | %.2f", v.nombre, v.valoracion, v.visualizaciones);
    }

    fclose(barch);
    fclose(tarch);

    return 0;
}