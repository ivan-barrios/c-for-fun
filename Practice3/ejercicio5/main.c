#include <stdio.h>
#include <stdlib.h>

struct dimensiones {
    double x;
    double y;
    double ancho;
    double alto;
} dim;

union udimensiones{
    dim separadas;
    double puntos[2][2];
    double juntos[4];
};


int main()
{




    return 0;
}
