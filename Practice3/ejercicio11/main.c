#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int sec : 5;  //Tengo 1 bit menos para representar segundos (31 seg)
    unsigned int min : 6;
    unsigned int hour : 5;
} Time;


void read(Time *t);
void imprimir(Time t);

int main()
{
    Time t;
    read(&t);
    imprimir(t);


    return 0;
}

void read(Time *t) {

    unsigned int aux;
    printf("Ingrese Hora: ");
    scanf("%u", &aux);
    t->hour = aux;

    printf("Ingrese Minutos: ");
    scanf("%u", &aux);
    t->min = aux;

    printf("Ingrese Segundos: ");
    scanf("%u", &aux);
    t->sec = aux;
}

void imprimir(Time t) {
    printf("La hora es: %u \n", t.hour);
    printf("Los minutos son: %u \n", t.min);
    printf("Los segundos son: %u \n", t.sec);
}
