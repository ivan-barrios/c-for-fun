// Se desea leer y procesar informaci�n de precipitaciones del mes de enero. Para ello se dispone de un
// archivo de texto (llamado precipitaciones.txt) con el siguiente formato:
// 0-2-0-0-7-22-11-0- . . . -0-
// Por cada de los 31 d�as se tiene un n�mero entero indicando los mil�metros llovidos, seguido de un
// gui�n medio (-) como delimitador. Escriba un programa que lea la informaci�n del archivo y
// derermine el d�a con mayor precipitaci�n. Para evaluar el programa, genere un archivo con el
// formato establecido utilizando un editor de texto plano (por ejemplo: Bloc de notas o Notepad++).
// Nota: puede utilizar la funci�n fscanf para procesar cada valor de precipitaci�n.


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
