#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("Error");
    }

    else{
        for(int i=1; i< argc; i++){
            printf("%s ", argv[i]);
        }
    }
    return 0;
}
