#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k;
    float spaces, realspaces;

    for (i = 1; i <= 9; i += 2) {
        spaces = 9 - i;
        for (j = 1; j < spaces; j += 2) {
            printf(" ");
        }
        for (k=1; k <= i; k++) {
            printf("*");
        }
        printf("\n");

    }
    for (i = 7; i >= 1; i -= 2) {
        spaces = 9 - i;
        for (j = 1; j < spaces; j += 2) {
            printf(" ");
        }
        for (k=1; k <= i; k++) {
            printf("*");
        }
        printf("\n");

    }


    return 0;
}
