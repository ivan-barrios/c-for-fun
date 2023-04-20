#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned vibrar : 1;
    unsigned linterna : 1;
    unsigned trasera : 1;
    unsigned frontal : 1;
    unsigned datos : 1;
    unsigned gps : 1;
    unsigned wifi : 1;
    unsigned bluetooth : 1;
} Modulos;


int main()
{
    Modulos estado_mod;

    //inactivo
    estado_mod.bluetooth = 0;      //AND 0 tambien

    //activo
    estado_mod.bluetooth = 1;      //OR 1 tambien

    //invierto
    estado_mod.bluetooth = ~estado_mod.bluetooth;

    //activo o inactivo?
    if (estado_mod.bluetooth == 1){
        printf("Activo");
    } else {
        printf("Inactivo");
    }



    return 0;
}
