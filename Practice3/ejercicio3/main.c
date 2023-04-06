#include <stdio.h>
#include <stdlib.h>
#define DIMF 3


struct direccion {
    char calle[50];
    char ciudad[30];
    int codigo_postal;
    char pais[40];
};
struct alu {
    char apellido[50];
    char nombre[50];
    char legajo[8];
    float promedio;
    struct direccion domicilio;
};

typedef struct alu alumno;



void initializeAlumno(alumno *);
int getMaxPromIndex(alumno [], int);

int main()
{   int maxPromIndex;
    alumno vecAlumnos[DIMF];
    for (int i = 0; i < DIMF; i++) {
        initializeAlumno(&vecAlumnos[i]);
    }
    maxPromIndex = getMaxPromIndex(vecAlumnos, DIMF);
    printf("El Alumno con mejor promedio es: %s %s", vecAlumnos[maxPromIndex].apellido, vecAlumnos[maxPromIndex].nombre);
    return 0;
}


void initializeAlumno(alumno *alu){
    printf("Ingrese Apellido: ");
    scanf("%s", alu->apellido);
    printf("Ingrese Nombre: ");
    scanf("%s", alu->nombre);
    printf("Ingrese Legajo: ");
    scanf("%s", alu->legajo);
    printf("Ingrese Promedio: ");
    scanf("%f", &alu->promedio);
}

int getMaxPromIndex(alumno vecAlu[], int longitud) {
    int i, maxIndex;
    float maxProm = 0;
    for (i = 0; i < longitud; i++) {
        if (vecAlu[i].promedio >= maxProm){
            maxProm = vecAlu[i].promedio;
            maxIndex = i;
        }
    }
    return maxIndex;
}



