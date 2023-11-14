#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int queue[MAX_NODES];
    int front, rear;
} Queue;

void enqueue(Queue *q, int value) {
    q->queue[q->rear++] = value;
}

int dequeue(Queue *q) {
    return q->queue[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

typedef struct {
    int nodes;
    int edges;
    int adjMatrix[MAX_NODES][MAX_NODES];
} Graph;

void initGraph(Graph *g, int nodes, int edges) {
    g->nodes = nodes;
    g->edges = edges;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v) {
    g->adjMatrix[u - 1][v - 1] = 2;
    g->adjMatrix[v - 1][u - 1] = 2;
}

void bfs(Graph *g, int start, int distances[]) {
    Queue q;
    q.front = 0;
    q.rear = 0;
    int visited[MAX_NODES] = {0};
    enqueue(&q, start);
    visited[start - 1] = 1;
    distances[start - 1] = 0;

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        for (int i = 0; i < g->nodes; i++) {
            if (g->adjMatrix[current - 1][i] != 0 && !visited[i]) {
                enqueue(&q, i + 1);
                visited[i] = 1;
                distances[i] = distances[current - 1] + 2;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph g;
    initGraph(&g, n, m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    int start;
    scanf("%d", &start);

    int distances[MAX_NODES];
    for (int i = 0; i < n; i++) {
        distances[i] = -1;
    }

    bfs(&g, start, distances);

    printf("BFS Traversal: ");
    for (int i = 0; i < n; i++) {
        if (distances[i] != -1) {
            printf("%d ", i + 1);
        }
    }

    printf("\nDistance [");
    for (int i = 0; i < n; i++) {
        printf("%d ", distances[i]);
    }
    printf("]\n");

    return 0;
}
