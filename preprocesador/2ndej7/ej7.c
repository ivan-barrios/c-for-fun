#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1

int main(){
    int x= 15;
    //y no estaba declarado
    int y= 0;
    while (x<50){
        #ifndef DEBUG
        printf("x= %d", x);
        y = y+1;
        #endif
        x++;
    }
    return 0;
}