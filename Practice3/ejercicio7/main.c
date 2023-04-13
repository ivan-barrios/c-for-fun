#include <stdio.h>
#include <stdlib.h>
#define LONG 20

typedef struct estudiante{
    char apellido[LONG];
    char nombre[LONG];
    char legajo[LONG];
    int nacionalidad;
    union{
        int DNI;
        char pasaporte[LONG];
    } id;
} Estudiante;



void read(Estudiante *est);
void imprimir(Estudiante est);

int main()
{
    Estudiante est;
    printf("Ingrese los datos: \n");
    read(&est);

    printf("%s", est.apellido);
    imprimir(est);


    return 0;
}

void read(Estudiante *est){
    printf("Apellido: ");
    scanf("%s", &(est->apellido));
    printf("Nombre: ");
    scanf("%s", est->nombre);
    printf("Legajo: ");
    scanf("%s", est->legajo);
    printf("Ingrese 0 para DNI o 1 para pasaporte: ");
    scanf("%d", &est->nacionalidad);
    printf(!est->nacionalidad ? "Ingese DNI: " : "Ingrese pasaporte: ");
    if (!est->nacionalidad){
        scanf("%d", &est->id.DNI);
    } else{
        scanf("%s", est->id.pasaporte);
    }
}


void imprimir(Estudiante est) {
    printf("Apellido: %s \n", est.apellido);
    printf("Nombre: %s \n", est.nombre);
    printf("Legajo: %s \n", est.legajo);
    if (est.nacionalidad){
        printf("Pasaporte: %s \n", est.id.pasaporte);
    } else {
        printf("DNI: %d \n", est.id.DNI);
    }



}
