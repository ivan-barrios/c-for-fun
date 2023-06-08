#include <stdio.h>
#include <stdlib.h>
#define max2(a, b) (((b) > (a)) ? (b) : (a))
#define max4(a, b, c, d) (max2(a, b) > max2(c, d) ? max2(a, b) : max2(c, d))


int main() {
    int a = 6;
    int b = 3;
    int c = 9;
    int d = 10;
    printf("%d", max4(a, b, c, d)); //GOOD :)
}