#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if(argc < 4){
        printf("No se paso la cantidad correcta de parametros");
    }
    else{

        switch (argv[2][0]) {
        case '+': printf("%d", atoi(argv[1]) + atoi(argv[3]));
        break;
        case '-': printf("%d", atoi(argv[1]) - atoi(argv[3]));
        break;
        case '*': printf("%d", atoi(argv[1]) * atoi(argv[3]));
        break;
        case '/': printf("%d", atoi(argv[1]) / atoi(argv[3]));
        break;
        default: printf("Hubo un error");
        }
    }



    return 0;
}
