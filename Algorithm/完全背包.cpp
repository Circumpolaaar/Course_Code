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
        for (int j = w[i]; j <= W; ++j) {
            dp[j] = (dp[j] > dp[j - w[i]] + v[i]) ? dp[j] : dp[j - w[i]] + v[i];
        }
    }

    printf("%d\n", dp[W]);
    return 0;
}

