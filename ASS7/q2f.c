#include <stdio.h>
#include <stdlib.h>

// Structure to represent a symbol
struct SYMBOL {
    char alphabet;
    int frequency;
};

// Structure to represent a node in the Huffman tree
struct Node {
    struct SYMBOL symbol;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(struct SYMBOL symbol) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform Min-Heapify
void minHeapify(struct Node* arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->symbol.frequency < arr[smallest]->symbol.frequency)
        smallest = left;

    if (right < n && arr[right]->symbol.frequency < arr[smallest]->symbol.frequency)
        smallest = right;

    if (smallest != i) {
        //printf("From here *a->%d, *b->%d\n",arr[i]->symbol.frequency,arr[smallest]->symbol.frequency);
        struct Node* temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
         //printf("*a->%d, *b->%d\n",arr[i]->symbol.frequency,arr[smallest]->symbol.frequency);
        minHeapify(arr, n, smallest);
    }
}

void min_heap(struct Node* nodes[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		minHeapify(nodes, n, i);
	}
}

// Function to build a Huffman tree -> min heap
struct Node* buildHuffmanTree(struct SYMBOL symbols[], int n) {
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(symbols[i]);
    }

    min_heap(nodes, n);

    int size = n;
    while (size > 1) {
        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct SYMBOL mergedSymbol;
        mergedSymbol.alphabet = '\0';
        mergedSymbol.frequency = left->symbol.frequency + right->symbol.frequency;

        struct Node* mergedNode = createNode(mergedSymbol);
        mergedNode->left = left;
        mergedNode->right = right;

        nodes[0] = mergedNode;

        for (int i = 1; i < size - 1; i++) {
            nodes[i] = nodes[i + 1];
        }

        size--;
        minHeapify(nodes, size, 0);
    }

    return nodes[0];
}

// Function to perform in-order traversal of the Huffman tree
void inorderTraversal(struct Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%c ", root->symbol.alphabet);
        inorderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL symbols[n];
    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet); // Use a space before %c to consume newline characters
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    // Build the Huffman tree
    struct Node* root = buildHuffmanTree(symbols, n);

    // Perform in-order traversal of the Huffman tree
    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}