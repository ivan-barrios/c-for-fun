#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Abro archivos con handleError
    FILE *f = fopen("numeros.txt", "w");
    if (f == NULL) {
        printf("Hubo un error al crear numeros.txt");
        return 1;
    }
    FILE *bf = fopen("numeros.dat", "wb");
    if (bf == NULL) {
        printf("Hubo un error al crear numeros.dat");
        return 1;
    }

    int n;
    printf("Ingrese un numero (Una cifra) (-1 para cortar) : ");
    scanf("%d", &n);

    while (n != -1) {

        fprintf(f, "%c", n + '0');
        fwrite(&n, sizeof(int), 1, bf);

        printf("Ingrese un numero (Una cifra) (-1 para cortar) : ");
        scanf("%d", &n);
    }

    printf("Successful task");

    fclose(f);
    fclose(bf);

    return 0;
}


/*
No es posible visualizar los numeros en el archivo binario porque ...?
En este caso son iguales de tamaño, pero sería mejor usar el archivo binario en el caso
de querer almacenar numeros grandes (Muchos digitos cada uno) porque estos ocuparian 4
4 bytes, mientras que cada digito en el archivo de texto, seria un caracter, el cual ocupa
1 byte cada uno, es decir si tiene mas de 4 digitos cada numero, es mejor usar archivos
binarios.
*/
