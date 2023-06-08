#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    if (argc <= 1){
        printf("Error");
        return 1;
    }

    float suma;
    for (int i=1; i<argc; i++){
        suma += atoi(argv[i]);
    }

    printf("El promedio es: %f", (suma/(argc-1)));

    return 0;
}