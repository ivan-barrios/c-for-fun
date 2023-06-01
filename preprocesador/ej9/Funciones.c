#include <stdio.h>
#include "imath.h"

int potencia(int x, int y) {
    for (int i=0; i<y; i++){
        x *= x;
    }
    return x;
}

int cuadrado(int x) {
    return x*x;
}

int cubo(int x){
    return x*x*x;
}

int absoluto(int i){
    if(i<0) return -i;
    return i;
}

int factorial (int i){
    if (i == 1) return 1;
    return i*(factorial(i-1));
}

int sumatoria (int i){
    int sum=0;
    for (int j=0; j<=i; j++){
        sum += i;
    }
    return sum;
}

int multiplo (int x, int y){
    return (x % y);
}

int divisor (int x, int y) {
    return !(y % x);
}

int par (int i) {
    return !(i % 2);
}
int impar (int i) {
    return i%2;
}
