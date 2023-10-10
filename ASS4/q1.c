#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int comparisons=0;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = (l + r)/ 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArrayToFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

int main() {
    clock_t start, end;
    start=clock();
    int choice;
    printf("Menu:\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. Exit\n");
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
        case 4:
            return 0;   
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
    printf("Before Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printArrayToFile(arr, n, outputFileName);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of comparisons made: %d\n", comparisons);
    end=clock();
    printf("Time taken by the program to run is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    

    return 0;
}







