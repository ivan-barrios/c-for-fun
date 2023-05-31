#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * argv[]) {
    printf("\nargc = %d",argc);
    printf("\nargv[0] => %s",argv[0]);
    return 0;
}

/*
Imprime argc = 1 porque hay un argumento
Por convención argv[0] es la ruta completa al programa
que se ejecuta, con lo cual argc vale por lo menos 1.
*/
