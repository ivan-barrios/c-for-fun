#include <stdio.h>
#include <stdlib.h>

#define COL 4
#define ROW 5

void sumaDeMatrices(const int [ROW][COL], const int [ROW][COL], int [ROW][COL] );

int main()
{
    int mA[ROW][COL] = { {10,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1} };
    int mB[ROW][COL] = { {1,1,1,1}, {1,1,1,1}, {1,9,1,1}, {1,1,1,1}, {1,1,1,1} };
    int mC[ROW][COL] = {0};

    sumaDeMatrices(mA, mB, mC);

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d   ", mC[i][j]);
        }
        printf("\n");
    }


    return 0;
}

void sumaDeMatrices(const int mA[ROW][COL], const int mB[ROW][COL], int mC[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            mC[i][j] = mA[i][j] + mB[i][j];
        }
    }

}
