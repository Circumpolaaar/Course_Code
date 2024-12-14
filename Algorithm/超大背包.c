#include <stdio.h>
long long int min(long long int a,long long int b) {
    return a < b ? a : b; // 返回两个整数中的最小值
}

int main() {
    long long int N, V;
    scanf("%lld%lld", &N, &V);
    long long int w[500], v[500];
    long long int maxV = 0;
    for (long long int i = 0; i < N; i++) {
        scanf("%lld%lld", &w[i], &v[i]);
        if (maxV < v[i]) maxV = v[i]; // 找出最大价值
    }
    
    // 初始化dp数组，设置为一个很大的值，表示初始状态下无法达到该价值
    long long int dp[maxV * N + 1]; // 调整dp数组的大小
    
    for (long long  i = 0; i <= maxV * N; i++) {
        dp[i] = (long long )V + 1;
    }
    dp[0] = 0;

    for (long long int i = 0; i < N; i++) {
        for (long long  int j = maxV * N; j >= v[i]; j--) {
            // 更新dp数组，尝试以更小的体积达到价值j
            dp[j] = min(dp[j], dp[j - v[i]] + (long long )w[i]);
        }
    }
    
    // 找出可以达到的最大价值
    long long  int maxValue = 0;
    for (long long int i = maxV * N; i >= 0; i--) {
        if (dp[i] <= (long long )V && dp[i] > 0) {
            maxValue = i;
            break; // 找到后立即退出循环
        }
    }

    printf("%lld\n", maxValue); // 输出可以达到的最大价值

    return 0;
}