#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;
typedef struct Vertex {
    int id;
    Edge* edges;
} Vertex;
typedef struct Graph {
    int numVertices;
    Vertex* vertices;
} Graph;
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->vertices = (Vertex*)malloc(numVertices * sizeof(Vertex));
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i].id = i;
        graph->vertices[i].edges = NULL;
    }
    return graph;
}
void addEdge(Graph* graph, int src, int dest, int weight) {
    // 添加或更新从src到dest的边
    Edge* edge = graph->vertices[src].edges;
    Edge* prev = NULL;
    while (edge != NULL) {
        if (edge->dest == dest) {
            // 如果新权重更小，则更新权重
            if (weight < edge->weight) {
                edge->weight = weight;
            }
            break;
        }
        prev = edge;
        edge = edge->next;
    }
    // 如果边不存在，则创建新的边并插入到链表头部
    if (edge == NULL) {
        Edge* newEdge = (Edge*)malloc(sizeof(Edge));
        newEdge->dest = dest;
        newEdge->weight = weight;
        newEdge->next = graph->vertices[src].edges;
        graph->vertices[src].edges = newEdge;
    }

    // 对于无向图，也需要添加从dest到src的边
    edge = graph->vertices[dest].edges;
    prev = NULL;
    while (edge != NULL) {
        if (edge->dest == src) {
            // 如果新权重更小，则更新权重
            if (weight < edge->weight) {
                edge->weight = weight;
            }
            break;
        }
        prev = edge;
        edge = edge->next;
    }
    // 如果边不存在，则创建新的边并插入到链表头部
    if (edge == NULL) {
        Edge* newEdge = (Edge*)malloc(sizeof(Edge));
        newEdge->dest = src;
        newEdge->weight = weight;
        newEdge->next = graph->vertices[dest].edges;
        graph->vertices[dest].edges = newEdge;
    }
}


int minKey(int key[], int mstSet[], int numVertices) {
    int min = INF, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void primMST(Graph* graph) {
    int numVertices = graph->numVertices;
    int parent[numVertices];
    int key[numVertices];
    int mstSet[numVertices];
    int totalWeight = 0;
    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet, numVertices);
        mstSet[u] = 1;
        Edge* edge = graph->vertices[u].edges;
        while (edge != NULL) {
            int v = edge->dest;
            if (mstSet[v] == 0 && edge->weight < key[v]) {
                parent[v] = u;
                key[v] = edge->weight;
            }
            edge = edge->next;
        }
    }
    for (int i = 1; i < numVertices; i++) {
        totalWeight += key[i];
    }
    printf("%d\n", totalWeight);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--; // 0-based indexing
        addEdge(graph, u, v, w);
    }
    primMST(graph);
    // 释放分配的内存
    for (int i = 0; i < n; i++) {
        Edge* edge = graph->vertices[i].edges;
        while (edge) {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(graph->vertices);
    free(graph);
    return 0;
}