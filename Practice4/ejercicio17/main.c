#include <stdio.h>
#include <stdlib.h>
#define N 10

int*** crearTensor(int t){
    int i,j;
    int*** a;
    a = (int***) calloc(t,sizeof(int**));
    for (i=0; i<t; i++){
        a[i] = (int**) calloc(t, sizeof(int*));
        for (j=0; j<t; j++){
            a[i][j] = (int*) calloc(t, sizeof(int));
        }
    }
    return a;
}

int main() {
    int*** e;
    e = crearTensor(N);
    return 0;
}

//Si N = 2 --> a es una direccion, de una direccion, a una direccion, a un entero. (Serian tres dimensiones)?

        1
       /
      *
     / \2
    *   3
   / \ /
  /   *
 /     \
a       4
 \
  \   *--5
   \ / \
    *   6
     \
      *--7
       \
        8



