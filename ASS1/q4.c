#include <stdio.h>

void EXCHANGE(int* p, int* q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int* p1, int p2) {
    if (p2 <= 0)
        return; 

    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(p1 + i, p1 + i - 1);
    }
}

int main() {
    int n,p2;
    printf("Enter the no of elements in array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements \n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("Enter the no of elements to right rotate : ");
    scanf("%d",&p2);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    ROTATE_RIGHT(arr, p2);

    printf("\nRotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}