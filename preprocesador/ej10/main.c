#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

int main()
{
    Stack *s = s_create();
    int n;
    printf("Ingrese numero a insertar en pila: ");
    scanf("%d", &n);

    while(n != 0) {
        s_push(s, n);
        printf("Ingrese numero a insertar en pila: ");
        scanf("%d", &n);
    }

    while(!s_empty(*s)){
        printf("Desapilado: %d \n", s_pop(s));
    }
    //Funciona bien! :)
    return 0;
}
