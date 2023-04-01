#include <stdio.h>
int main(){
    float resultado;
    int x,y;
    char a;

    printf("Ingrese el primer numero:");
    scanf("%d", &x);
    printf("Ingrese el segundo numero:");
    scanf("%d", &y);
    printf("Ingrese el caracter");
    scanf(" %c", &a);

    switch (a) {
        case '+': resultado = x + y;
        break;
        case '-': resultado = x - y;
        break;
        case '*': resultado = x * y;
        break;
        case '/': resultado = x / y;
        default: printf("Ingrese un operador valido\n");
    }

    printf("%.2f", resultado);

    return 0;
}
