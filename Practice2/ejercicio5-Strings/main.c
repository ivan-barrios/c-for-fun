#include <stdio.h>
#include <stdlib.h>

char* strcpy(char [], const char[]);

int main()
{
    char destino[20];
    char fuente[20] = "ihsanjdnaijdna";

    printf("%s", strcpy(destino, fuente));

    return 0;
}


//recibo char destination[] o char* destination???????????????????????????????????
char* strcpy(char* destino, const char* fuente) {
    //No se aloco memoria
    if (destino == NULL) return NULL;

    //Para no perder el puntero al primer caracter
    char *ptr = destino;

    while (*fuente != '\0') {
        *destino = *fuente;
        destino++;
        fuente++;
    }

    //incluyo el \0
    *destino = '\0';

    return ptr;
}
