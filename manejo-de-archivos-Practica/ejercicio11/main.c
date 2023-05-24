#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("../ejercicio9/data", "rb");
    if (f == NULL) {
        printf("No se pudo abrir el archivo");
        return 1;
    }

    //Voy al final del archivo
    fseek(f, 0, SEEK_END);
    //Imprimo tamaño
    printf("El tamanio del archivo es: %ld", ftell(f));

    fclose(f);


    return 0;
}

//El tamaño del archivo es de 168 bytes porque hay 3 structs adentro
//Esos structs tienen 2 strings de 20 caracteres (40 bytes);
// tiene 3 unsigned int (12 bytes)
// tiene 1 int (4 bytes);

// (40 + 12 + 4) * 3 = (56) * 3 = 168 bytes

//VAMOO
