/*
Un archivo csv (Comma Separated Values) contiene información separada por comas. Cada renglón
(fila) contiene un registro de información. Cada columna contiene un campo particular de
información. La primera fila es especial ya que contiene los nombres de los campos.
Se desea obtener información a partir del archivo llamado vinos.csv (el cual se encuentra en la
Sección “Ing. Gral. y Contenidos” del curso de la cátedra en WebUNLP). El programa debe generar
un archivo de texto con un resumen que indique el valor máximo, mínimo y promedio para cada
uno de los campos del archivo. Este archivo debe llamarse reporte_vinos.txt y debe guardarse en la
misma ruta que el archivo vinos.csv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIML 8

typedef struct {
    float max;
    float min;
    float prom;
} info;


void cargarCampos(FILE **arch, char campos[][50], int dimL);
void inicializar(info resumen[], int dimL);
void cargarResumen(FILE **arch, info resumen[], int dimL);
void cargarEnArchivo(FILE **arch, char campos[][50], info resumen[], int dimL);


int main() {

    //Abro archivo
    FILE *arch = fopen("vinos.csv", "r");

    //Error handler
    if(arch == NULL) {
        printf("No se pudo abrir el archivo vinos.csv");
        return 1;
    }

    //Cargo nombres de los campos:
    char campos[DIML][50];
    cargarCampos(&arch, campos, DIML);

    //Cargo valores para el resumen (Actualizando max, min y prom
    info resumen[DIML]; //(Tiene Max, Min, Prom)
    inicializar(resumen, DIML);
    cargarResumen(&arch, resumen, DIML);

    fclose(arch); //Cierro archivo

    //Creo nuevo archivo para almacenar mi resumen
    FILE *res = fopen("reporte_vinos.txt", "w");

    //Error handler
    if (res == NULL) {
        printf("No se pudo crear el archivo reporte_vinos!");
        return 1;
    }

    //Imprimo mi resumen en el archivo
    cargarEnArchivo(&res, campos, resumen, DIML);

    //Cierro archivo
    fclose(res);

    return 0;
}




void cargarCampos(FILE **arch, char campos[][50], int dimL) {
    char campo[50];
    for(int i=0; i<dimL; i++) {
        fscanf(*arch, "%[^;];", campo);
        strcpy(campos[i], campo);
    }
}



void inicializar(info resumen[], int dimL) {
    for (int i=0; i<dimL; i++) {
        resumen[i].max = 0;
        resumen[i].min = 9999;
        resumen[i].prom = 0;
    }
}



void cargarResumen(FILE **arch, info resumen[], int dimL) {
    float num;
    char trash[20];
    int cond, cont = 0;

    while (!feof(*arch)) {
        cont++;
        for(int i=0; i<dimL; i++) {
            cond = fscanf(*arch, "%f;", &num);
            if (cond != 0) {
                if(num > resumen[i].max)
                    resumen[i].max = num;
                if(num < resumen[i].min)
                    resumen[i].min = num;
                resumen[i].prom += num;
            }
        }
        fscanf(*arch, "%s\n", trash);
    }
    for(int i=0; i<dimL; i++) {
        resumen[i].prom /= cont;
    }
}



void cargarEnArchivo(FILE **arch, char campos[][50], info resumen[], int dimL) {

    for(int i=0; i<dimL; i++)
        fprintf(*arch, "%s\t", campos[i]);
    fprintf(*arch, "\n");
    fprintf(*arch, "Max:\t");
    for(int i=0; i<dimL; i++)
        fprintf(*arch, "%.2f \t", resumen[i].max);
    fprintf(*arch, "\n");
    fprintf(*arch, "Min:\t");
    for(int i=0; i<dimL; i++)
        fprintf(*arch, "%.2f \t", resumen[i].min);
    fprintf(*arch, "\n");
    fprintf(*arch, "Prom:\t");
    for(int i=0; i<dimL; i++)
         fprintf(*arch, "%.2f \t", resumen[i].prom);

}


