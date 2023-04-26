#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        a. La función malloc reserva memoria sin inicializarla, mientras que la función calloc reserva memoria e inicializa todos los bytes a 0.
        realloc se usa para cambiar el tamaño de la memoria asignada previamente, conservando el contenido existente.


        b. Sí, se puede utilizar realloc en lugar de malloc pasándole un puntero NULL como primer argumento. Si realloc se invoca con el valor 0
        como parámetro de tamaño, se comportará como la función free, liberando la memoria.


        c. El operador sizeof devuelve el tamaño en bytes de un tipo de dato o de una variable. Es útil para reservar memoria dinámicamente porque
        permite calcular cuánta memoria se necesita para almacenar cierto número de elementos de un tipo específico.
    */

    return 0;
}
