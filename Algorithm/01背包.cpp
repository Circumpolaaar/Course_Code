//����¼ 
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
//��̬�滮
#include <stdio.h>

#define MAX_N 1000
#define MAX_W 1000

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsackDP(int W, int weights[], int values[], int n) {
    int dp[MAX_N+1][MAX_W+1];
    
    // ��ʼ��dp����
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }
    
    // ���dp����
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
    
    printf("��������Ʒ�����ͱ���������");
    scanf("%d %d", &n, &W);
    
    printf("������ÿ����Ʒ�������ͼ�ֵ��ÿ��һ����Ʒ�������ͼ�ֵ����\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    
    int maxValue = knapsackDP(W, weights, values, n);
    printf("����ֵΪ��%d\n", maxValue);
    
    return 0;
}
//�����������(DFS)
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
    
    // ��ѡ��ǰ��Ʒ
    dfs(i+1, cw, cv);
    
    // ѡ��ǰ��Ʒ��ǰ������Ʒ���Է��뱳����
    if (cw + weights[i] <= W) {
        dfs(i+1, cw + weights[i], cv + values[i]);
    }
}

int main() {
    printf("��������Ʒ�����ͱ���������");
    scanf("%d %d", &n, &W);
    
    printf("������ÿ����Ʒ�������ͼ�ֵ��ÿ��һ����Ʒ�������ͼ�ֵ����\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    
    dfs(0, 0, 0);
    printf("����ֵΪ��%d\n", maxValue);
    
    return 0;
}

