#include <stdio.h>
#include <stdlib.h>

typedef enum {VIBRAR = 1, LINTERNA = 2, TRASERA = 4, FRONTAL = 8, DATOS = 16, GPS = 32, WIFI = 64, BLUETOOTH = 128} bitsEnum;

const bitsEnum todosPrendidos = 255;
const bitsEnum todosApagados = 0;

int main()
{
    bitsEnum prueba = todosPrendidos;

    //prueba |= BLUETOOTH;                 //ACTIVA
    //printf("%d", prueba);

    prueba &= ~(BLUETOOTH);                 //APAGA
    //printf("%d", prueba);


    //prueba ^= BLUETOOTH;                 //INVIERTE
    //printf("%d", prueba);

    printf("%d", (prueba & WIFI));



    return 0;
}
