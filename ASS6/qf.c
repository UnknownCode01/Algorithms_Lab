#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
int display(struct person *p, int n);

void swap(struct person *a, struct person *b)
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(struct person *max_heap, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int Largest = i;

    if (left < n && max_heap[left].weight > max_heap[Largest].weight)
        Largest = left;

    if (right < n && max_heap[right].weight > max_heap[Largest].weight)
        Largest = right;

    if (Largest != i)
    {
        swap((max_heap + Largest), (max_heap + i));
        max_heapify(max_heap, n, i);
    }
}
void min_heapify(struct person *min_heap, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int Smallest = i;
    if (left < n && min_heap[left].age < min_heap[Smallest].age)
    {
        Smallest = left;
    }
    if (right < n && min_heap[right].age < min_heap[Smallest].age)
    {
        Smallest = right;
    }
    if (Smallest != i)
    {
        swap((min_heap + Smallest), (min_heap + i));
        min_heapify(min_heap, n, i);
    }
}

void build_min_heap(struct person *min_heap, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        min_heapify(min_heap, n, i);
    }
}
void build_max_heap(struct person *max_heap, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(max_heap, n, i);
    }
}

void display_youngest_weight(struct person *min_heap)
{
    printf("Weight of youngest student: %.2f kg\n", min_heap[0].weight * 0.453592);
}

void delete_oldest_person(struct person *min_heap, int *n2)
{
    int index;
    if (*n2 == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    int i = *n2 / 2;
    
    struct person *lo = (min_heap + i);
    for (int j = i; j < *n2; j++)
    {
        if (min_heap[j].age >= lo->age)
        {
            lo = (min_heap + j);
            index = j;
        }
    }
    printf("Oldest person %s deleted from the Min-heap.\n", lo->name);
    if (index == *n2 - 1)
    {
        *n2=*n2-1;
        printf("Displaying after deleting oldest person\n");
        display(min_heap, *n2);
        free(min_heap + *n2);
    }
    else
    {
        index++;
        while (index < *n2)
        {
            *(min_heap + index - 1) = *(min_heap + index);
            index++;
        }

        free(min_heap + *n2 - 1);
        *n2 = *n2 - 1;
        printf("Displaying after deleting oldest person\n");
        display(min_heap, *n2);
    }
}

int display(struct person *p, int n)
{
    printf("Id\tName\t\tAge\tHeight\tWeight\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\n", p[i].id, p[i].name, p[i].age, p[i].height, p[i].weight);
    }
    return 0;
}

void insert_person(struct person *min_heap, int *n)
{
    int pno = *n;
    int uno = *n;
    uno++;

    struct person *x = min_heap;
    printf("Enter new person's data (id name age height weight): \n");
    scanf("%d %s %d %d %d", &x[pno].id, x[pno].name, &x[pno].age, &x[pno].height, &x[pno].weight);

    int i = uno - 1;
    while (i > 0)
    {
        int j = ((i + 1) / 2) - 1;
        if (min_heap[j].age > min_heap[i].age)
        {
            swap((min_heap + i), (min_heap + j));
            i = j;
        }
        else
            break;
    }
    *n = uno;
}

int main()
{
    int option, n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    int n1 = n, n2 = n, n3 = n;
    FILE *file1 = fopen("file.txt", "r");
    if (file1 == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    struct person *p = (struct person *)malloc(n * sizeof(struct person));
    struct person *min_heap = (struct person *)malloc(n * sizeof(struct person));
    struct person *max_heap = (struct person *)malloc(n * sizeof(struct person));
    for (int i = 0; i < n; i++)
    {
        p[i].name = (char *)malloc(40);
        fscanf(file1, "%d %s %d %d %d", &p[i].id, p[i].name, &p[i].age, &p[i].height, &p[i].weight);
    }
    fclose(file1);
    FILE *file2 = fopen("file.txt", "r");
    for (int i = 0; i < n; i++)
    {
        min_heap[i].name = (char *)malloc(40);
        fscanf(file2, "%d %s %d %d %d", &min_heap[i].id, min_heap[i].name, &min_heap[i].age, &min_heap[i].height, &min_heap[i].weight);
    }
    fclose(file2);
    FILE *file3 = fopen("file.txt", "r");
    for (int i = 0; i < n; i++)
    {
        max_heap[i].name = (char *)malloc(40);
        fscanf(file3, "%d %s %d %d %d", &max_heap[i].id, max_heap[i].name, &max_heap[i].age, &max_heap[i].height, &max_heap[i].weight);
    }
    fclose(file3);
    struct person new_person;
    new_person.name = (char *)malloc(40);

    while (1)
    {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            display(p, n1);
            break;
        case 2:
            build_min_heap(min_heap, n2);
            printf("Min-heap based on age created.\n");
            printf("Displaying Min-heap based on age.\n");
            display(min_heap, n2);
            break;
        case 3:
            build_max_heap(max_heap, n3);
            printf("Max-heap based on weight created.\n");
            printf("Displaying Max-heap based on weight.\n");
            display(max_heap, n3);
            break;
        case 4:
            display_youngest_weight(min_heap);
            break;
        case 5:
            min_heap = (struct person *)realloc(min_heap, (n2 + 1) * sizeof(struct person));
            min_heap[n2].name = (char *)malloc(40);
            insert_person(min_heap, &n2);
            printf("Displaying after adding new member\n");
            display(min_heap, n2);

            break;
        case 6:
            delete_oldest_person(min_heap, &n2);
            break;
        case 7:
            for (int i = 0; i < n; i++)
            {
                free((min_heap + i)->name);
            }
            free(min_heap);
            for (int i = 0; i < n; i++)
            {
                free((max_heap + i)->name);
            }
            free(max_heap);
            return 0;
        default:
            printf("Invalid option. Please choose a valid option.\n");
        }
    }

    return 0;
}
