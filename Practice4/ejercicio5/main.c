#include <stdio.h>
#include <stdlib.h>
#define LENGTH 100

char * reservaMem(char * pa, int n);
void processSentence(char sentence[], int * letrasMinus, int * letrasMayus);


int main()
{
    char * pArr;
    char sentence[LENGTH];
    int letrasMinus = 0, letrasMayus = 0;
    //int * minusPtr = &letrasMinus, mayusPtr = &letrasMayus;
    int i;

    pArr = reservaMem(pArr, LENGTH);

    for (i = 0; i < 10; i++) {
        printf("Your sentence: ");
        gets(sentence);
        processSentence(sentence, &letrasMinus, &letrasMayus);
        printf("La cantidad de letras minusculas y mayusculas de la oracion %d son: %d %d", i, letrasMinus, letrasMayus);
        letrasMinus = 0;
        letrasMayus = 0;
        printf("\n");
    }

    return 0;
}

char * reservaMem(char * p, int n) {
    p = (char *) malloc(sizeof(char)*n);
    return p;
}


void processSentence(char sentence[], int * letrasMinus, int * letrasMayus) {
    int i;

    for(i = 0; sentence[i] != '\0'; i++) {
        if ((sentence[i] >= 'a') && (sentence[i] <= 'z') )
            *letrasMinus += 1;
        else if ((sentence[i] >= 'A') && (sentence[i] <= 'Z'))
            *letrasMayus += 1;
    }



}


