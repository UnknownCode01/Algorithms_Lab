#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n, int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        if(j >= 0 && arr[j] > key){
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
        }}
        else
        (*comparisons)++;

        arr[j + 1] = key;
    }
}

void printArrayToFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    // fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

int main() {
    int choice;
    printf("Menu:\n");
    printf("1. Ascending Order Input\n");
    printf("2. Descending Order Input\n");
    printf("3. Random Order Input\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    const char *inputFileName;
    const char *outputFileName;
    switch (choice) {
        case 1:
            inputFileName = "inAsce.dat";
            outputFileName = "outInsAsce.dat";
            break;
        case 2:
            inputFileName = "inDesc.dat";
            outputFileName = "outInsDesc.dat";
            break;
        case 3:
            inputFileName = "inRand.dat";
            outputFileName = "outInsRand.dat";
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Failed to open input file\n");
        return 1;
    }

    int n=10;
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }
    fclose(inputFile);

    int comparisons = 0;
    insertionSort(arr, n, &comparisons);
    printArrayToFile(arr, n, outputFileName);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of comparisons made: %d\n", comparisons);

    if (comparisons == (n - 1) * n / 2) {
        printf("Input scenario: Worst case\n");
    } else if (comparisons == (n - 1)) {
        printf("Input scenario: Best case\n");
    } else {
        printf("Input scenario: Random case\n");
    }

    return 0;
}
