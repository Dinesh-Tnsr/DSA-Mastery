#include <stdio.h>

int main() {
    /* network of 4 nodes:
       Wire from 0 to 1
       Wire from 0 to 2
       Wire from 1 to 2
       Wire from 2 to 3
    */

    int A[4][4] = {0};

    A[0][1] = 1;
    A[1][0] = 1;
    A[0][2] = 1;
    A[2][0] = 1;
    A[1][2] = 1;
    A[2][1] = 1;
    A[2][3] = 1;
    A[3][2] = 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}