#include <stdio.h>
#include <stdlib.h>

enum dias {DOMINGO, LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO};


void imprimir1(int dia){
    printf("%d", dia);
}

void imprimir2(){

}

int main()
{
    int dia = SABADO;

    imprimir1(dia);

    imprimir2(VIERNES);


    return 0;
}
