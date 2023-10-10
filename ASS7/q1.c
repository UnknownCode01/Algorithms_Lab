#include <stdio.h>
#include <stdlib.h>

struct ITEM
{
	int id;
	float profit;
	float weight;
	float ratio;
	float ht;
};

typedef struct ITEM ITEM;

void swap(ITEM *a, ITEM *b)
{
	ITEM *temp;
	temp = (ITEM *)malloc(sizeof(ITEM));
	*temp = *a;
	*a = *b;
	*b = *temp;
	free(temp);
};

void max_heapify(ITEM *max_heap, int n, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int Largest = i;

	if (left < n && max_heap[left].ratio > max_heap[Largest].ratio)
		Largest = left;

	if (right < n && max_heap[right].ratio > max_heap[Largest].ratio)
		Largest = right;

	if (Largest != i)
	{
		swap((max_heap + Largest), (max_heap + i));
		max_heapify(max_heap, n, i);
	}
}

void max_heap(ITEM *max_heap, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		max_heapify(max_heap, n, i);
	}
}

void heap_sort(ITEM *I, int n)
{
	while (n > 1)
	{
		swap(I, I + n - 1);
		n--;
		max_heapify(I, n, 0);
	}
}

void fks(ITEM *I, int n, float c)
{
	int i;
	printf("\nEnter the id, profits and weights of each object:- \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d %f %f", &I[i].id, &I[i].profit, &I[i].weight);
	}

	for (i = 0; i < n; i++)
	{
		I[i].ratio = I[i].profit / I[i].weight;
	}

	max_heap(I, n);
	heap_sort(I, n);

	for (i = n - 1; i >= 0; i--)
	{
		if (I[i].weight <= c)
		{
			I[i].ht = 1;
			c -= I[i].weight;
		}
		else
		{
			I[i].ht = c / I[i].weight;
			c = 0;
			break;
		}
	}

	printf("id\tprofit\tweight\tprofit/weight\tAmount to be taken\n");
	for (i = n - 1; i >= 0; i--)
	{
		printf("%d\t%.2f\t%.2f\t%.2f\t\t%.4f\n", I[i].id, I[i].profit, I[i].weight, I[i].ratio, I[i].ht);
	}
}
int main()
{
	int num;
	float capacity;
	printf("\nEnter the no. of objects:- ");
	scanf("%d", &num);
	ITEM *I = (ITEM *)malloc(num * sizeof(ITEM));
	printf("\nEnter the capacity of knapsack or Bag carrying weight capacity:- ");
	scanf("%f", &capacity);
	fks(I, num, capacity);

	return (0);
}
