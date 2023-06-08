#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

float ** crearMatriz(int n);

void sumaMatrices(float **m1, float **m2, float **m3, int n);

void liberarMatriz(float **m, int n);

#endif