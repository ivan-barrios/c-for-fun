#include <stdio.h>
#include <stdlib.h>

int main()
{
    float km, resultado;

    scanf("%f", &km);
    resultado = km / 1.61;
    printf("%.2f km equivalen a %.2f millas", km, resultado);


    return 0;
}
