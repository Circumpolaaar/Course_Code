#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 2010

int n, m; // n是点数，m是边数
int graph[MAXN][MAXN]; // 邻接矩阵存储图的边权
int key[MAXN]; // 关键值数组
int parent[MAXN]; // 最小生成树的父节点数组
int inMST[MAXN]; // 是否包含在最小生成树中的标记数组

// 查找关键值最小且不在MST中的顶点
int minKey() {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < n; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Prim算法实现
void primMST() {
    // 初始化关键值为无限大，父节点为-1，MST标记为0
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = 0;
    }

    // 从第一个顶点开始
    key[0] = 0;
    parent[0] = -1;

    // 构建最小生成树
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(); // 选择关键值最小且不在MST中的顶点
        inMST[u] = 1; // 标记为包含在MST中

        // 更新邻接顶点的关键值和父节点
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
     // 输出最小生成树的边权
    for (int i = 1; i < n; i++) {
        printf("%d %d %d\n", parent[i] + 1, i + 1, graph[i][parent[i]]);
    }
    
    // 输出最小生成树的总边权
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        totalWeight += graph[i][parent[i]];
    }
    printf("%d\n", totalWeight);
}

// 主函数
int main() {
    scanf("%d %d", &n, &m);

    // 初始化图的邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j) ? 0 : INT_MAX; // 无边设置为INT_MAX，自身到自身的边设置为0
        }
    }

    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--,v--;
        if(graph[u][v]>w){
            graph[u][v] = w;
            graph[v][u] = w;
        }
        
    }

    primMST();

    return 0;
}