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
    scanf("%d%d",&n,&m);

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
            //graph[v[i]][u[i]] = w[i];
        }
    }

    floyd_warshall(n);
    scanf("%d",&q);
    while (q--) {
        int s, t;
        scanf("%d %d", &s, &t);
        s--; t--;
        
        if (graph[s][t]!=INF) {
            printf("%lld\n",graph[s][t]);
        }else{
            printf("-1\n");
        }
        
    }

    return 0;
}