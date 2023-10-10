#include <stdio.h>

void findSecondSmallestAndLargest(int arr[], int n) {
    if (n < 2) {
        printf("Array size should be at least 2.\n");
        return;
    }

    int smallest = arr[0], secondSmallest = arr[0];
    int largest = arr[0], secondLargest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }

        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    printf("Second Smallest Element: %d\n", secondSmallest);
    printf("Second Largest Element: %d\n", secondLargest);
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 0;
    }

    int arr[n];

    FILE *file;
    file = fopen("input1.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    findSecondSmallestAndLargest(arr, n);

    return 0;
}
