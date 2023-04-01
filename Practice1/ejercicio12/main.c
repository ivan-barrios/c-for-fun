#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i;

    for (i = 1; i <= 10; i++) {
        printf("Square Root of %d : %.2f \n", i, sqrt(i));
        printf("%d Squared : %.2f \n", i, pow(i, 2));
        printf("%d to the three: %.2f \n", i, pow(i, 3));
    }
    return 0;
}
