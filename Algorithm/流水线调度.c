#include<stdio.h>
#include<string.h>
#include <limits.h> 
#include <stdlib.h>
int p[6][10010] = {0}; 
int t[6][6] = {0}; 
long long int dp[6][10010] = {0}; 
long long int findmin(long long a, long long b, long long c) {
    long long int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int m;
        scanf("%d", &m);
        for (int j = 1; j <= 3; j++) {
            for (int i = 1; i <= m; i++) {
                scanf("%d", &p[j][i]);
            }
        }
        for (int j = 1; j <= 3; j++) {
            for (int i = 1; i <= 3; i++) {
                scanf("%d", &t[j][i]);
            }
        }
        
        for (int i = 1; i <= 3; i++) {
            dp[i][1] = p[i][1];
        }
        
        for (int i = 2; i <= m; i++) { // 注意从2开始，因为第1列已经初始化了
            for (int j = 1; j <= 3; j++) {
                long long int min_time = LLONG_MAX;
                for (int k = 1; k <= 3; k++) { // 对于上一个作业的所有阶段
                    long long int time = dp[k][i-1] + t[k][j] + p[j][i];
                    if (time < min_time) {
                        min_time = time;
                    }
                }
                dp[j][i] = min_time;
            }
            long long int sum = findmin(dp[1][m], dp[2][m], dp[3][m]);
            printf("%lld\n", sum); 
        }
    }

    return 0;
}
