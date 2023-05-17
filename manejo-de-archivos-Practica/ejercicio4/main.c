/*
Se desea leer y procesar informaci�n de un listado de apuestas. Para ello se dispone de un archivo
de texto (llamado apuestas.txt) con el siguiente formato:
c�digo_de_apuesta|monto_apostado; � ; c�digo_de_apuesta|monto_apostado;
Donde cada apuesta se compone de un n�mero entero (c�digo de apuesta) y un n�mero flotante
(monto apostado). Escriba un programa que procese la informaci�n del archivo e informe el monto
total apostado.
Ejemplo: 1|100.0;65|50.5;23|34.5; debe informar: �El monto total apostado es $185�.
Nota: Intente resolver el problema leyendo cada tupla (c�digo, monto) al mismo tiempo.
*/




#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arch = fopen("apuestas.txt", "r");
    if (!arch) {
        printf("Hubo un error al abrir el archivo");
        return 1;
    }

    float montoTotal = 0;
    int code;
    float monto;

    fscanf(arch, "%d|%f;", &code, &monto);
    while (!feof(arch)) {
        montoTotal += monto;
        fscanf(arch, "%d|%f;", &code, &monto);
    }

    printf("El monto total es: $%f", montoTotal);

    fclose(arch);

    return 0;
}
