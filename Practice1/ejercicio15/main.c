#include <stdio.h>
#include <stdlib.h>

unsigned factorial (unsigned);

int main()
{
    unsigned num;

    printf("Introduzca el numero del que quiere el factorial: ");
    scanf("%d", &num);

    printf("El factorial de %d es: %d \n", num, factorial(num));

    return 0;
}

unsigned factorial (unsigned n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}
