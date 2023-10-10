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
        struct Node* temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
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

struct Node* extract_node(struct Node* nodes[], int *n)
{
    struct Node* temp = nodes[0];
    nodes[0]=nodes[*n-1];
    *n=*n-1;
    minHeapify(nodes,*n,0);
    return temp;    
}

void insert_heap(struct Node* nodes[], int *n,struct Node* temp){
    nodes[*n]=temp;
    *n=*n+1;
    int i=*n-1,j;
    while(i>0){
        j=((i+1)/2)-1;
        if(nodes[j]>nodes[i]){
            struct Node* temp = nodes[i];
            nodes[i] = nodes[j];
            nodes[j] = temp;
            i=j;
        }
        else break;
    }
}

// Function to perform in-order traversal of the Huffman tree
void inorderTraversal(struct Node* root) {


    if (root->left==NULL && root->right==NULL){
        printf("%c ",root->symbol.alphabet);
    } 
    else{
        if(root->left!=NULL){
            inorderTraversal(root->left);
        }
        if(root->right!=NULL){
            inorderTraversal(root->right);
        }
    }
}


// Function to build a Huffman tree -> min heap
struct Node* buildHuffmanTree(struct SYMBOL symbols[], int n) {
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(symbols[i]);
    }

    min_heap(nodes, n);

    while (n > 1) {
        struct Node* p = extract_node(nodes,&n);
        struct Node* q = extract_node(nodes,&n);

        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->symbol.alphabet = '*';
        temp->symbol.frequency = p->symbol.frequency+q->symbol.frequency;
        temp->left=p;
        temp->right=q;
        insert_heap(nodes,&n,temp);
    }
    return nodes[0];
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
    printf("In-order traversal of the tree (Huffman): \n");
    inorderTraversal(root);

    return 0;
}