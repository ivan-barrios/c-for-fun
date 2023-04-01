#include <stdio.h>
#include <stdlib.h>

void minmax(int n, float *max, float *min);

int main()
{ int n;
    float max = -1, min = 9999999999;

    printf("Ingrese el numero de numeros a comparar: ");
    scanf("%d", &n);

    minmax(n, &max, &min);

    printf("El maximo es %f y el minimo es %f", max, min);

    return 0;
}

void minmax(int n, float *max, float *min){
    int i;
    float num;

    for (i = 1; i <= n; i++){
        printf("Ingrese un numero: ");
        scanf("%f", &num);
        if (num < *min) {
            *min = num;
        }
        if (num > *max) {
            *max = num;
        }
    }
}
