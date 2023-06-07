#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    if (argc < 2) {
        printf("Cantidad incorrecta de argumentos para el programa\n");
        exit(EXIT_FAILURE);
    }
    float suma = 0;
    for (int i=1; i<argc; i++){
        suma += atof(argv[i]);
    }
    printf("Prom: %f\n", suma/(argc-1));
    return 0;
}