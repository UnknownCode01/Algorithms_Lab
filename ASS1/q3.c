#include <stdio.h>

// Function to find the total number of duplicate elements in the array
int countDuplicates(int arr[], int size)
{
    int count = 0;

    for (int i = 0; i < size-1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
    }

    return count;
}

// Function to find the most repeating element in the array
int mostRepeatingElement(int arr[], int size)
{
    int maxCount = 0;
    int mostRepeatingElem = arr[0];

    for (int i = 0; i < size-1; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            mostRepeatingElem = arr[i];
        }
    }

    return mostRepeatingElem;
}

int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    FILE *file;
    file = fopen("input2.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
        printf("%d ",arr[i]);
    }
    fclose(file);
    printf("\nTotal number of duplicate values : %d  \n", countDuplicates(arr, n));
    printf("The most repeating element in the array : %d  \n", mostRepeatingElement(arr, n));

    return 0;
}
