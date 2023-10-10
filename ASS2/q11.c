#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimal, FILE *outputFile) {
    if (decimal > 0) {
        decimalToBinary(decimal / 2, outputFile);
        fprintf(outputFile, "%d", decimal % 2);
    }
}

int main() {
    int n;
    printf("Enter the value of 'n': ");
    scanf("%d", &n);

    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int decimal;
        fscanf(inputFile, "%d", &decimal);
        
        decimalToBinary(decimal, outputFile);
        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Binary conversion completed and saved to output.txt.\n");

    return 0;
}
