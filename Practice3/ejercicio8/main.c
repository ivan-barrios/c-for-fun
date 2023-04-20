#include <stdio.h>
#include <stdlib.h>

int main()
{
    //typedef enum { IZQUIERDA, CENTRO_H, DERECHA } AlineacionHorizontal;
                   //0        //1       //2
    //typedef enum { ARRIBA=1, CENTRO_V, ABAJO } AlineacionVertical;
                   //1       //2       //3
    //typedef enum { DOS=2, CERO=0, UNO, MENOS_UNO=-1, OTRO } Numeros;
                   //2    //0     //1  //-1          //0
    //typedef enum { LET_A = "A", LET_B, LET_Z = "Z" } Letras;
                   //No compila porque no esta enumerado, (Hay Strings por " ".)
    typedef enum { LETRA_A = 'A', LETRA_B, LETRA_Z = 'Z' } Letras2;

    Letras2 letra = LETRA_Z;

    printf("%c", letra);



    return 0;
}
