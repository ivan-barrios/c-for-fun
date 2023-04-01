#include <stdio.h>
#include <stdlib.h>
#define DIMF 5

void swap(int *, int *);
void invertirVector(int vec[]);

int main()
{
    int vec[DIMF] = {1,2,3,4,5};

    for (int i = 0; i < DIMF; i++) {
        printf("%d  ", vec[i]);
    }

    printf("\n");

    invertirVector(vec);

    for (int i = 0; i < DIMF; i++) {
        printf("%d  ", vec[i]);
    }


    return 0;
}

void invertirVector(int *vec) {
    int i, *direc2;

    direc2 = vec + DIMF - 1;

    for (i = 0; i < DIMF/2; i++) {
        swap(vec, direc2);
        vec++;
        direc2--;
    }

}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
