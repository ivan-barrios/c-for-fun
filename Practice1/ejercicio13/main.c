#include <stdio.h>
#include <stdlib.h>

int esPrimo(int);

int main()
{

    for (int i = 1; i < 50; i++) {
        if (esPrimo(i)) {
            printf("El numero %d ES PRIMO \n", i);
        } else {
            printf("El numero %d NO ES PRIMO \n", i);
        }
    }


    return 0;
}

int esPrimo(int a) {
    if (a == 0 || a == 1) return 0;

    for (int x = 2; x < a; x++) {
        if (a % x == 0) return 0;
    }
    return 1;
}
