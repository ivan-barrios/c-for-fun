#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esPalindroma(const char []);

void invertirPalabra(char []);

void swap(char *, char *);

int main()
{
    char arr[] = "rotor";

    if (!esPalindroma(arr)) printf("%s Es palindroma.", arr);
    else printf("%s NO es palindroma.", arr);

    return 0;
}

int esPalindroma(const char arr[]) {
    char copiedArr[strlen(arr)];
    strcpy(copiedArr, arr);

    invertirPalabra(copiedArr);

    return (strcmp(copiedArr, arr));

}

void invertirPalabra(char *arr) {
    int i;
    char *direc2;

    direc2 = arr + strlen(arr) - 1;

    for (i = 0; i < strlen(arr)/2; i++) {
        swap(arr, direc2);
        arr++;
        direc2--;
    }

}

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
