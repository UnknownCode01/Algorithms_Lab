#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comparisons = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        
        while (arr[i] <= pivot && i < high)
        {
            i++;
            comparisons++;
        }
        while (arr[j] > pivot && j > low)
        {
            j--;
            comparisons++;
        }
        if (i < j)
        {
            comparisons++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArrayToFile(int arr[], int n, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Failed to open file %s\n", filename);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

int main()
{
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
    switch (choice)
    {
    case 1:
        inputFileName = "inAsce.dat";
        outputFileName = "outInsAsce1.dat";
        break;
    case 2:
        inputFileName = "inDesc.dat";
        outputFileName = "outInsDesc1.dat";
        break;
    case 3:
        inputFileName = "inRand.dat";
        outputFileName = "outInsRand1.dat";
        break;
    case 4:
        return 0;
    default:
        printf("Invalid choice\n");
        return 1;
    }

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL)
    {
        printf("Failed to open input file\n");
        return 1;
    }

    int n = 10;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(inputFile, "%d", &arr[i]);
    }
    fclose(inputFile);
    printf("Before Sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printArrayToFile(arr, n, outputFileName);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of comparisons made: %d\n", comparisons);
    if (comparisons == (n * (n + 1) / 2)-1)
    {
        printf("Partition scenario: Worst-case\n");
    }
    else if (comparisons == n)
    {
        printf("Partition scenario: Best-case\n");
    }
    else
    {
        printf("Partition scenario: Average-case\n");
    }

    return 0;
}
