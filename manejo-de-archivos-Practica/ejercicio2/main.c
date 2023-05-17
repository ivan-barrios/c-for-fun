//Escriba un programa que procese un archivo de texto e informe la cantidad de caracteres
//minúsculas, mayúsculas y dígitos que posee.



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int cantMayus = 0, cantMinus = 0, cantDigits = 0;

    //Descarto contenido y creo otro nuevo para leerlo
    //Y procesarlo despues
    FILE *arch = fopen("text2.txt", "w");
    if (!arch) {
        printf("No se pudo crear el archivo");
        return 1;
    }

    //Cadena para ingresar al archivo
    char string[300];

    //Leo el input del Usuario
    printf("Ingrese datos al archivo: ");
    gets(string);

    //Lo pongo en el archivo
    if (fprintf(arch, string) < 0) {
        printf("Hubo un error en la escritura del archivo");
        return 1;
    };
    fclose(arch);

    arch = fopen("text2.txt", "r");
    if (!arch) {
        printf("No se pudo abrir el archivo");
        return 1;
    }

    int c;

    //Ahora leo en el archivo para completar consigna
    c = fgetc(arch);
    while (!feof(arch)) {
        if (isupper(c)) cantMayus++;
        if (islower(c)) cantMinus++;
        if (isdigit(c)) cantDigits++;
        c = fgetc(arch);
    }

    fclose(arch);


    printf("Cantidad de mayusculas: %d \n", cantMayus);
    printf("Cantidad de minusculas: %d \n", cantMinus);
    printf("Cantidad de digitos: %d \n", cantDigits);


    return 0;
}
