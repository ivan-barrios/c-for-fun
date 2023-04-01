#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* replace(char [], char, char);

int main()
{
    char cadena[] = "jajajjajajaajja";

    printf("%s", replace(cadena, 'a', 'o'));


    return 0;
}

char* replace(char cadena[], char c1, char c2) {

    for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] == c1) cadena[i] = c2;
    }
    return cadena;
}
