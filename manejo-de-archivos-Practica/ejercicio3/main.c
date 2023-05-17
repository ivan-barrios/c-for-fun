// Se desea leer y procesar información de precipitaciones del mes de enero. Para ello se dispone de un
// archivo de texto (llamado precipitaciones.txt) con el siguiente formato:
// 0-2-0-0-7-22-11-0- . . . -0-
// Por cada de los 31 días se tiene un número entero indicando los milímetros llovidos, seguido de un
// guión medio (-) como delimitador. Escriba un programa que lea la información del archivo y
// derermine el día con mayor precipitación. Para evaluar el programa, genere un archivo con el
// formato establecido utilizando un editor de texto plano (por ejemplo: Bloc de notas o Notepad++).
// Nota: puede utilizar la función fscanf para procesar cada valor de precipitación.


#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arch = fopen("precipitaciones.txt", "r");
    if (!arch) {
        printf("Hubo un error al abrir el archivo");
        return 1;
    }

    //Contador del dia y dia maximo
    int count = 1, maxDia;
    //numero actual y numero maximo
    int num, maxNum = 0;

    //El %*c hace un skip del caracter.
    fscanf(arch, "%d%*c", &num);
    while (!feof(arch)) {
        //Proceso dia
        if (num > maxNum) {
            maxDia = count;
            maxNum = num;
        }
        //Proximo dia:
        count++;
        fscanf(arch, "%d%*c", &num);
    }
    if (num > maxNum) {
            maxDia = count;
            maxNum = num;
    }

    printf("La maxima precipitacion es: %d en el dia %d de enero", maxNum, maxDia);

    fclose(arch);


    return 0;
}
