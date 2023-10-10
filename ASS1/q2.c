#include <stdio.h>
int main() {

    int arr1[]={3,4,7,5,2,9};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[n];
    arr2[0]=arr1[0];
    for(int i=1;i<n;i++){
        arr2[i]=arr1[i]+arr2[i-1];
    }
    printf("Input Array :\n");
    for(int i=0;i<n;i++)
    printf("%d ",arr1[i]);
    printf("\nOutput Array :\n");
    for(int i=0;i<n;i++)
    printf("%d ",arr2[i]);

    
    return 0;
}