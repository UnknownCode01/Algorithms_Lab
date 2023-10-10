#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main(int argc, char *argv[]) {
if (argc != 3)
    {
        printf("Usage : %s ,<value1> <value2> \n", argv[0]);
        return 1;
    }
    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    int num1, num2, result;

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fscanf(inputFile, "%d %d", &num1, &num2) == 2) {
        result = gcd(num1, num2);
        fprintf(outputFile, "GCD of %d and %d is %d\n", num1, num2, result);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("GCD calculations are done. Results stored in output2.txt.\n");
    return 0;
}

