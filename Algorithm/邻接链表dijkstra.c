#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include<math.h>

#define MAX_NODES 100010
#define INF LLONG_MAX

typedef struct Edge {
    long long to, weight;
    struct Edge* next;
} Edge;

typedef struct {
    long long node, dist;
} MinHeapNode;
long long min(long long a,long long b){
    if(a>b) return b;
    else return a;
}
typedef struct {
    long long size;
    long long capacity;
    long long *pos;
    MinHeapNode **array;
} MinHeap;

Edge* graph[MAX_NODES];
long long dist[MAX_NODES];
long long p[MAX_NODES];
long long result[MAX_NODES];

Edge* newEdge(long long to, long long weight, Edge* next) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->to = to;
    edge->weight = weight;
    edge->next = next;
    return edge;
}

void addEdge(long long u, long long v, long long w) {
    graph[u] = newEdge(v, w, graph[u]);
}

MinHeapNode* newMinHeapNode(long long v, long long dist) {
    MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    minHeapNode->node = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

MinHeap* createMinHeap(long long capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (long long*)malloc(capacity * sizeof(long long));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, long long idx) {
    long long smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist) {
        smallest = right;
    }

    if (smallest != idx) {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->node] = idx;
        minHeap->pos[idxNode->node] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

int isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap)) {
        return NULL;
    }

    MinHeapNode* root = minHeap->array[0];
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->node] = minHeap->size - 1;
    minHeap->pos[lastNode->node] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(MinHeap* minHeap, long long v, long long dist) {
    long long i = minHeap->pos[v];

    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->node] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->node] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

int isInMinHeap(MinHeap* minHeap, long long v) {
    if (minHeap->pos[v] < minHeap->size) {
        return 1;
    }
    return 0;
}

void dijkstra(long long n, long long src, long long dist[MAX_NODES]) {
    MinHeap* minHeap = createMinHeap(n);

    for (long long v = 0; v < n; ++v) {
        dist[v] = INF;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    minHeap->size = n;

    while (!isEmpty(minHeap)) {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        long long u = minHeapNode->node;

        Edge* edge = graph[u];
        while (edge != NULL) {
            long long v = edge->to;

            if (isInMinHeap(minHeap, v) && dist[u] != INF && edge->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + edge->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            edge = edge->next;
        }
    }

    free(minHeap->array);
    free(minHeap->pos);
    free(minHeap);
}

int main() {
    long long t;
    scanf("%lld", &t);

    while (t--) {
        long long n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);

        for (long long i = 0; i < n; i++) {
            graph[i] = NULL;
        }

        for (long long i = 0; i < k; i++) {
            scanf("%lld", &p[i]);
        }

        for (long long i = 0; i < m; i++) {
            long long u, v;
            long long w;
            scanf("%lld %lld %lld", &u, &v, &w);
            addEdge(u, v, w);
        }

        dijkstra(n, 0, dist);

        long long final_result = INF;
        for (long long i = 0; i < k; i++) {
            dijkstra(n, p[i], result);
            if (dist[p[i]] != INF && result[n - 1] != INF) {
                final_result = min(final_result, dist[p[i]] + result[n - 1]);
            }
        }

        if (final_result == INF) {
            printf("-1\n");
        } else {
            printf("%lld\n", final_result);
        }

        for (long long i = 0; i < n; i++) {
            Edge* edge = graph[i];
            while (edge) {
                Edge* tmp = edge;
                edge = edge->next;
                free(tmp);
            }
        }
    }

    return 0;
}