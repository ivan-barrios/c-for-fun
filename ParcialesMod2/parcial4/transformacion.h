#ifndef TRANSFORMACION_H_INCLUDED
#define TRANSFORMACION_H_INCLUDED
#define MAX 30

typedef struct valoracion{
    char nombre[MAX];
    int visualizaciones;
    float valoracion;
} Valoracion;

int transformacion(char *n1, char *n2);


#endif