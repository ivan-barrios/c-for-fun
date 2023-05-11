//a) Se pueden modelar un vector de 2*3 posiciones y una matriz (de 2x3) (con todos los elementos
//     puestos secuencialmente en memoria
//b) Si, se puede de la siguiente forma:
//      La fila 1 va a estar de m[0] hasta m[2] (3 elementos)
//      La fila 2 va a estar de m[3] hasta m[5] (3 elementos)
//c)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f, c;

    int x=2, y=3;
    int * m= (int*) malloc(x*y*sizeof(int));

    for(f=0; f<x; f++){
        printf("Ingrese fila %d: ", f);
        for(c=0; c<y; c++){
            scanf("%d", &m[f*x + c]);
        }
    }

    for(f=0; f<x; f++){
        for(c=0; c<y; c++){
            printf(" %d ", m[f*x + c]);
        }
        printf("\n");
    }

    //COMO HAGO PARA QUE NO SE SOBREESCRIBA EL VALOR CUANDO CAMBIA DE FILA?
    free(m);
    return 0;
}
