#include <stdio.h>
#include <stdlib.h>

int strlen(char []);

int main()
{
    char cadena[] = "asdasdasdasd";

    printf("%d", strlen(cadena));

    return 0;
}

int strlen(char cadena[]) {
    int i = 0;

    while (cadena[i] != '\0') {
        i++;
    }
    return i;
}
