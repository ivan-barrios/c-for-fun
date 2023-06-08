#include "matriz.h"

float ** crearMatriz(int n){
    float ** m = (float **) malloc(n * sizeof(float *));
    for (int i=0; i<n; i++) {
        m[i] = malloc(n * sizeof(float));
    }
    return m;
}

void sumaMatrices(float **m1, float **m2, float **m3, int n) {
    int i,j;
    for (i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void liberarMatriz(float **m, int n) {
    int i;
    for (i=0; i<n; i++) {
        free(m[i]);
    }
    free(m);
}