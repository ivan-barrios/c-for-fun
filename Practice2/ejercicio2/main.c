#include <stdio.h>
#include <stdlib.h>

float promedio(const float [], int);
float minimo(const float [], int);
float maximo(const float [], int);

int main()
{
    float arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("El promedio es: %f \n", promedio(arr, 10));
    printf("El minimo es: %f \n", minimo(arr, 10));
    printf("El maximo es: %f \n", maximo(arr, 10));


    return 0;
}

float promedio(const float arr[], int longitud) {
    float prom;

    for (int i = 0; i < longitud; i++) {
        prom += arr[i];
    }

    return (prom/longitud);
}

float minimo(const float arr[], int longitud) {
    float min = 9999999999;

    for (int i = 0; i < longitud; i++) {
        if (arr[i] < min) min = arr[i];
    }

    return min;
}

float maximo(const float arr[], int longitud) {
    float max = -999999999;

    for (int i = 0; i < longitud; i++) {
        if (arr[i] > max) max = arr[i];
    }

    return max;
}


