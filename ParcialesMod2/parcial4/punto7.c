#include <stdio.h>
#include <stdlib.h>

typedef struct piramide {
    int **elementos;
    int base;
} Piramide;

Piramide crear_piramide(int n);
void liberar_piramide(Piramide p, int n);

int main() {
    return 0;
}


Piramide crear_piramide(int n) {
    Piramide p;
    p.base = n;
    p.elementos = malloc(n * sizeof(int *));
    for (int i = 0; i<n; i++){
        p.elementos[i] = malloc((i+1) * sizeof(int));
    }
    return p;
}

void liberar_piramide(Piramide p, int n) {
    for (int i=0; i<n; i++){ 
        free(p.elementos[i]);
    }
    free(p.elementos);
}