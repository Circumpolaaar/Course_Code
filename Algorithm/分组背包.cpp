#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_M 100
#define MAX_W 1000
#define INF 0x3f3f3f3f

int N, M, W;
int w[MAX_N][MAX_M], v[MAX_N][MAX_M];
int dp[MAX_W + 1];

int main() {
    scanf("%d %d %d", &N, &M, &W);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d %d", &w[i][j], &v[i][j]);
        }
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; ++i) {
        for (int j = W; j >= 0; --j) {
            for (int k = 0; k < M; ++k) {
                if (j >= w[i][k]) {
                    dp[j] = (dp[j] > dp[j - w[i][k]] + v[i][k]) ? dp[j] : dp[j - w[i][k]] + v[i][k];
                }
            }
        }
    }

    printf("%d\n", dp[W]);
    return 0;
}

