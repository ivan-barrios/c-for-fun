#include <stdio.h>
#include <stdlib.h>
#define size 25 //Compilacion

void imprimir(int * v, int cant){
    int i;
    for (i=0; i<cant; i++)
        printf("v[%d]= %d", i, v[i]);
}
//No se puede usar un define en los parametros de una funcion

int main(){
    int v[size];
    imprimir(v, size); //compilacion en size
    return 0;
}

