#include <stdio.h>
#include <stdlib.h>

void pmm(const float [], int, float *, float *, float *);

int main()
{
    float arr[10] = {5, 2, 3, 4, 89, 6, 90, 8, 9, 10};
    float prom = 0, min = 99999, max = -99999;

    pmm(arr, 10, &prom, &min, &max);

    printf("El promedio es: %f \n El minimo es: %f \n El maximo es: %f \n", prom, min, max);

    return 0;
}

void pmm(const float arr[], int longitud, float *prom, float *min, float *max) {

    for (int i = 0; i < longitud; i++) {
        *prom += arr[i];
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
    *prom /= 10;
}
