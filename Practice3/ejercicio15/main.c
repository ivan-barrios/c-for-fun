#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {CIRCULO, CUADRADO, RECTANGULO, TRIANGULO, ELIPSE} numFiguras;

typedef struct{
    float radio;
}Circulo;

typedef struct{
    float lado;
}Cuadrado;

typedef struct{
    float base;
    float altura;
}Rectangulo;

typedef struct{
    float base;
    float altura;
}Triangulo;

typedef struct{
    float radioMenor;
    float radioMayor;
}Elipse;


typedef union{
    Circulo circulo;
    Cuadrado cuadrado;
    Rectangulo rectangulo;
    Triangulo triangulo;
    Elipse elipse;
}UFigura;

typedef struct{
    int tipoDeFigura;
    UFigura figura;
}SFigura;


float calcularSuperficie(SFigura fig);
void leer(SFigura *fig);

int main()
{
    SFigura fig;
    leer(&fig);
    printf("La superficie de la figura es: %f", calcularSuperficie(fig));

    return 0;
}

float calcularSuperficie(SFigura fig){
    float sup;
    int tipo = fig.tipoDeFigura;
    switch (tipo) {
        case CIRCULO: sup = 3.1416 * pow(fig.figura.circulo.radio, 2); break;
        case CUADRADO: sup = pow(fig.figura.cuadrado.lado, 2); break;
        case RECTANGULO: sup = fig.figura.rectangulo.base * fig.figura.rectangulo.altura; break;
        case TRIANGULO: sup = (fig.figura.triangulo.base * fig.figura.triangulo.altura)/2; break;
        case ELIPSE: sup = 3.1416 * fig.figura.elipse.radioMenor * fig.figura.elipse.radioMayor; break;
    }
    return sup;
}

void leer(SFigura *fig) {
    printf("Ingrese el tipo de figura: ");
    scanf("%d", &fig->tipoDeFigura);

    int tipo = fig->tipoDeFigura;

    switch (tipo) {
        case CIRCULO:
            printf("Ingrese el radio del circulo: \n");
            scanf("%f", &fig->figura.circulo.radio);
            break;
        case ELIPSE:
            printf("Ingrese radio menor: ");
            scanf("%f", &fig->figura.elipse.radioMenor);
            printf("Ingrese radio mayor: ");
            scanf("%f", &fig->figura.elipse.radioMayor);
            break;
        case TRIANGULO:
            printf("Ingerse base del triangulo: ");
            scanf("%f", &fig->figura.triangulo.base);
            printf("Ingerse altura: ");
            scanf("%f", &fig->figura.triangulo.altura);
            break;
        case CUADRADO:
            printf("Ingrese el lado del cuadrado: \n");
            scanf("%f", &fig->figura.cuadrado.lado);
            break;
        case RECTANGULO:
            printf("Ingrese base del rectangulo: \n");
            scanf("%f", &fig->figura.rectangulo.base);
            printf("Ingrese altura del rectangulo: \n");
            scanf("%f", &fig->figura.rectangulo.altura);
            break;
    }
}





