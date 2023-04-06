#include <stdio.h>
#include <stdlib.h>


struct Pun3D {
    float x;
    float y;
    float z;
};
typedef struct Pun3D Punto3D;




int main()
{
    Punto3D arreglo[4];

    printf("%d \n", sizeof(struct Pun3D)); //Tamaño 12 (3 enteros de 4 bytes)

    printf("%d \n", sizeof(Punto3D));

    printf("%d", sizeof(arreglo));

    return 0;
}
