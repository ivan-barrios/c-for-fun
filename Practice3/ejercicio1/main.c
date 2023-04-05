#include <stdio.h>
#include <stdlib.h>
#define DIMF 5

struct rectangulo{
    float base;
    float altura;
};

typedef struct rectangulo Rec;

void inicializarRectangulo(Rec *);
float calcularArea(Rec);
void inicializarRectangulos(Rec [], int);
void imprimirRec(Rec [], int);
void imprimirMenorArea(Rec [], int);

int main()
{
    Rec rec[DIMF];
    inicializarRectangulos(rec, DIMF);
    imprimirRec(rec, DIMF);
    imprimirMenorArea(rec, DIMF);

    return 0;
}

void inicializarRectangulo(Rec *rec) {
    printf("Ingrese base: ");
    scanf("%f", &rec->base);
    printf("Ingrese altura: ");
    scanf("%f", &rec->altura);
}

void inicializarRectangulos(Rec rec[], int largo) {
    for (int i = 0; i < largo; i++ ) {
        printf("Ingrese base: ");
        scanf("%f", &rec[i].base);
        printf("Ingrese altura: ");
        scanf("%f", &rec[i].altura);
    }
}

void imprimirRec(Rec rec[], int largo) {
    for (int i = 0; i < largo; i++ ) {
        printf("Base: %f ", rec[i].base);
        printf("Altura: %f ", rec[i].altura);
        printf("\n");
    }

}

void imprimirMenorArea(Rec rec[], int largo) {
    int min;
    float minArea = 9999999;

    for (int i = 0; i < largo; i++) {
        if (minArea > calcularArea(rec[i])) {
            minArea = calcularArea(rec[i]);
            min = i;
        }
    }
    printf("%d", min);
}

float calcularArea(Rec rec) {
    return (rec.base) * (rec.altura);
}
