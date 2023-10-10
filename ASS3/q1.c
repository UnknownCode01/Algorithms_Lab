#include <stdio.h>

int binarySearchLeftmost(int arr[], int n, int target, int *comparisons) {
    int left = 0;
    int right = n - 1;
    int position = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        (*comparisons)++;

        if (arr[mid] == target) {
            position = mid;
            right = mid - 1;  // Search on the left half for leftmost appearance
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return position;
}

int main() {
    int n,target,comparisons=0;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to be searched : ");
    scanf("%d",&target);
    
    int position = binarySearchLeftmost(arr, n, target, &comparisons);

    if (position != -1) {
        printf("Element %d found at position %d\n", target, position);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    printf("Number of comparisons made: %d\n", comparisons);

    return 0;
}
