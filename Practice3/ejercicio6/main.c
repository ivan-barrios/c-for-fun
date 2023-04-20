#include <stdio.h>
#include <stdlib.h>

typedef union ufecha {
    struct sfecha{
        short int year;
        char month;
        char day;
    } datos_fecha;
    int comp;
} Fecha;


int main()
{
    Fecha fecha1;
    fecha1.datos_fecha.day = 3;
    fecha1.datos_fecha.month = 12;
    fecha1.datos_fecha.year = 2003;

    Fecha fecha2;
    fecha2.datos_fecha.day = 3;
    fecha2.datos_fecha.month = 12;
    fecha2.datos_fecha.year = 2003;

    printf(fecha1.comp == fecha2.comp ? "Son iguales" : "Son distintos");

    printf("fecha1: %d del %d del %d", fecha1.datos_fecha.day, fecha1.datos_fecha.month, fecha1.datos_fecha.year);


    return 0;
}
