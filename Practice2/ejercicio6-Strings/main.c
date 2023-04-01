#include <stdio.h>
#include <stdlib.h>

#define DIMF 26

void contadorDeCaracteres(const char [], int []);

int main()
{

    char palabra[DIMF];
    int res[DIMF] = {0};
    char abc[DIMF] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    //SE LEE LA PALABRA
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    //SE GUARDA EL RESULTADO EN res
    contadorDeCaracteres(palabra, res);

    for (int i = 0; i < DIMF; i++) {
        printf("%c ", abc[i]);
    }
    printf("\n");

    for (int i = 0; i < DIMF; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}

void contadorDeCaracteres(const char palabra[], int res[]) {

    for (int i = 0; palabra[i] != '\0'; i++) {
        res[(int) palabra[i] - 'a']++;
    }
}
