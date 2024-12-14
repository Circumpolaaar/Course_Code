//备忘录 
#include <stdio.h>
#include <string.h>
#define MAX_N 1000
#define MAX_W 1000
#define INF 0x3f3f3f3f

int N, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_W + 1];

int main() {
    scanf("%d %d", &N, &W);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &w[i], &v[i]);
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; ++i) {
        for (int j = W; j >= w[i]; --j) {
            dp[j] = (dp[j] > dp[j - w[i]] + v[i]) ? dp[j] : dp[j - w[i]] + v[i];
        }
    }

    printf("%d\n", dp[W]);
    return 0;
}
//动态规划
#include <stdio.h>

#define MAX_N 1000
#define MAX_W 1000

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsackDP(int W, int weights[], int values[], int n) {
    int dp[MAX_N+1][MAX_W+1];
    
    // 初始化dp数组
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }
    
    // 填充dp数组
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][W];
}

int main() {
    int n, W;
    int weights[MAX_N], values[MAX_N];
    
    printf("请输入物品数量和背包容量：");
    scanf("%d %d", &n, &W);
    
    printf("请输入每个物品的重量和价值（每行一个物品的重量和价值）：\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    
    int maxValue = knapsackDP(W, weights, values, n);
    printf("最大价值为：%d\n", maxValue);
    
    return 0;
}
//深度优先搜索(DFS)
#include <stdio.h>

#define MAX_N 1000
#define MAX_W 1000

int max(int a, int b) {
    return a > b ? a : b;
}

int weights[MAX_N], values[MAX_N];
int n, W;
int maxValue = 0;

void dfs(int i, int cw, int cv) {
    if (i == n || cw == W) {
        maxValue = max(maxValue, cv);
        return;
    }
    
    // 不选择当前物品
    dfs(i+1, cw, cv);
    
    // 选择当前物品（前提是物品可以放入背包）
    if (cw + weights[i] <= W) {
        dfs(i+1, cw + weights[i], cv + values[i]);
    }
}

int main() {
    printf("请输入物品数量和背包容量：");
    scanf("%d %d", &n, &W);
    
    printf("请输入每个物品的重量和价值（每行一个物品的重量和价值）：\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    
    dfs(0, 0, 0);
    printf("最大价值为：%d\n", maxValue);
    
    return 0;
}

