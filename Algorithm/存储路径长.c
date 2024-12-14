#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF LLONG_MAX
#define MAXN 510

long long graph[MAXN][MAXN];

void floyd_warshall(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);

    //初始化
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(i==j){
                graph[i][j]=0;
            } else {
                graph[i][j]=INF;
            }
        }
    }

    //读取
    int u[m],v[m];
    long long w[m];
    for (int i=0;i<m;i++) {
        scanf("%d%d%lld",&u[i],&v[i],&w[i]);
        u[i]--,v[i]--;
        if (graph[u[i]][v[i]] > w[i]) {
            graph[u[i]][v[i]] = w[i];
            graph[v[i]][u[i]] = w[i];
        }
    }

    floyd_warshall(n);

    while (q--) {
        int s, t, k;
        scanf("%d %d %d", &s, &t, &k);
        s--; t--; k--;
        int u_k = u[k], v_k = v[k];
        long long w_k = w[k];
        bool found = false;
        
        if (graph[s][u_k] != INF && graph[v_k][t] != INF && graph[s][u_k] + w_k + graph[v_k][t] == graph[s][t]) {
            found = true;
        }
        if (graph[s][v_k] != INF && graph[u_k][t] != INF && graph[s][v_k] + w_k + graph[u_k][t] == graph[s][t]) {
            found = true;
        }

        if (found) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}