#include <stdio.h>
#include <stdlib.h>

/*
Escriba un programa que calcule e imprima el promedio de 4 n�meros que se pasan como argumentos a
la funci�n main. En caso de no pasar la cantidad necesaria de par�metros, informar al usuario.
*/

int main(int argc, char * argv[])
{

    if(argc < 4){
        printf("No se paso la cantidad correcta de parametros");
    }
    else {
        int suma = 0;
        for(int i=1; i<argc; i++){

            suma += atoi(argv[i]);
            printf("SUMA %d - ", suma);
        }



        float prom =  ((float)suma/(argc-1));
        printf("%f", prom);
    }



    return 0;
}
