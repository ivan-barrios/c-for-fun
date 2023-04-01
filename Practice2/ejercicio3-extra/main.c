#include <stdio.h>
#include <stdlib.h>
#define DIMF 20
void upperStr(char *);
void lowerStr(char *);
void numToStr(int, char *);

int main()
{
    char cadena[DIMF];
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    printf("Antes: %d \n", num);
    numToStr(num, cadena);
    printf("Despues: %s", cadena);

    return 0;
}
void upperStr(char *cadena) {
    while (*cadena != '\0') {
        if (*cadena >= 'a' && *cadena <= 'z') {
            *cadena = *cadena - ('a' - 'A');
        }
        cadena++;
    }
}
void lowerStr(char *cadena) {
    while (*cadena != '\0') {
        if (*cadena >= 'A' && *cadena <= 'Z') {
            *cadena = *cadena + ( 'a' - 'A');
        }
        cadena++;
    }
}

void numToStr(int num, char *cadena) {
    while (num != 0) {
        *cadena = (char)(num % 10) + '0';
        num /= 10;
        cadena++;
    }
    //SE TIENE QUE INVERTIR DESPUES
}



