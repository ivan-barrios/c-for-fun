#include <stdio.h>
#include <stdlib.h>
#define MAX_SINONIMOS 3
#define TAM_PALABRA 20

typedef struct sinonimos {
    char palabra[TAM_PALABRA];
    int cant_sinonimos;
    char sinonimos[MAX_SINONIMOS][TAM_PALABRA];
} sinonimos_t;


int main() {
    FILE * bin = fopen("sinonimos.dat", "rb");
    if (!bin) {
        printf("No se pudo abrir el archivo b\n");
        return 1;
    }
    FILE * txt = fopen("sinonimos.txt", "w");
    if (!txt) {
        printf("No se pudo abrir el archivo\n");
        fclose(bin);
        return 1;
    }

    sinonimos_t sinonimo;
    int i;

    fread(&sinonimo, sizeof(sinonimos_t), 1, bin);
    while (!feof(bin)) {
        fprintf(txt, "%s | ", sinonimo.palabra);
        for (i = 0; i<sinonimo.cant_sinonimos; i++){
            fprintf(txt, "%s | " , sinonimo.sinonimos[i] );
        }
        fread(&sinonimo, sizeof(sinonimos_t), 1, bin);
    }
    return 0;
}