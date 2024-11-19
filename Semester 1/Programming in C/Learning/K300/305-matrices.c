/* matrices */
// TO DO 1: Extend the programm such that the result is printed
// TO DO 2: Extend the programm such that it also calculates the product of the two 3x3 matrices.
// TO DO 3: What happens when you make a mistake with the indices, e.g. read/write m1[3][0], m1[4][0], m1[0][4] etc.? 

#include <stdio.h>

int main() {
    const float m1[3][3] = {{12, 5.3, 10.0}, {5, 10.2, -2}, {1, -1, 3}};
    const float m2[3][3] = {{2.1, -3, 1.5}, {10, -12, 3.1}, {4, 8.2, -2}};
    float sum[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }

    printf("The sum is: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%6.2f\t", sum[i][j]);
        }
        printf("\n");
    }

    float product[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            product[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                product[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    printf("\nThe product is: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%6.2f\t", product[i][j]);
        }
        printf("\n");
    }
}
