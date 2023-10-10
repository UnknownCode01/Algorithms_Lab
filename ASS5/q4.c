#include <stdio.h>
#include <math.h>

int roundToNearestInt(double num) {
    return (int) (num + 0.5);
}

void createRoundedMatrix(double matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = roundToNearestInt(matrix[i][j]);
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    double matrix[n][n];

    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    createRoundedMatrix(matrix, n);
    printf("Rounded matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", (int) matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
