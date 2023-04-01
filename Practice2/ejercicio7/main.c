#include <stdio.h>
#include <stdlib.h>

#define ANOS 10
#define MESES 120

void calcularMenores(const int [ANOS][MESES]);


int main()
{
    int info[ANOS][MESES] = {0}; //SE DISPONE


    calcularMenores(info);


    return 0;
}

void calcularMenores(const int info[ANOS][MESES]) {
    int mes, minLluvia = 99999999;
    int ano, minProm = 99999999;


    for (int i = 0; i < ANOS; i++) {
        int suma = 0;
        for (int j = 0; j < MESES; j++) {
            if (minLluvia > info[i][j]) {
                minLluvia = info[i][j];
                mes = j;
            }
            suma += info[i][j];
        }
        if (minProm >= (suma/12)) {
            minProm = suma/12;
            ano = i;
        }
        printf("El mes que menos llovio en el ano nro %d fue el %d \n", i, mes);
    }
    printf("El ano con menor precipitacion promedio es el %d", ano);
}
