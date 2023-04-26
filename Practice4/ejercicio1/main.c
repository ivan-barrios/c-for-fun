#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        a. La funci�n malloc reserva memoria sin inicializarla, mientras que la funci�n calloc reserva memoria e inicializa todos los bytes a 0.
        realloc se usa para cambiar el tama�o de la memoria asignada previamente, conservando el contenido existente.


        b. S�, se puede utilizar realloc en lugar de malloc pas�ndole un puntero NULL como primer argumento. Si realloc se invoca con el valor 0
        como par�metro de tama�o, se comportar� como la funci�n free, liberando la memoria.


        c. El operador sizeof devuelve el tama�o en bytes de un tipo de dato o de una variable. Es �til para reservar memoria din�micamente porque
        permite calcular cu�nta memoria se necesita para almacenar cierto n�mero de elementos de un tipo espec�fico.
    */

    return 0;
}
