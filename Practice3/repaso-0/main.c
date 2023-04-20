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

void invertirPalabra(char s1[]) {
    int cant = strlen(s1);
    char * s2 = s1 + cant - 1;

    char temp;

    for (; cant/2 > 0; s1++, s2--) {
        temp = *s1;
        *s1 = *s2;
        *s2 = temp;
        cant--;
    }

    s1 = s2 + 1;
}

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
