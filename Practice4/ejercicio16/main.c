#include <stdio.h>
#include <stdlib.h>

void agregarDivisor(int **divisores, int cantDivisores, int div) {
    *divisores = realloc(*divisores, cantDivisores * sizeof(int));
    (*divisores)[cantDivisores - 1] = div;
}


int main()
{
    int n, i, cantDivisores = 0;
    int *divisores = NULL;

    //Leo numero
    printf("Ingresar numero: ");
    scanf("%d", &n);

    //Me fijo los elementos que son divisores y los agrego.
    for(i=1; i<=n; i++) {
        if(!(n % i)) {
            cantDivisores++;
            agregarDivisor(&divisores, cantDivisores, i);
        }
    }

    //Imprimo
    printf("Los divisores de %d son: ", n);
    for (i=0; i<cantDivisores; i++) {
        printf("%d, ", divisores[i]);
    }

    free(divisores);

    return 0;
}
