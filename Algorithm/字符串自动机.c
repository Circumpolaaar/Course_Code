#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

// 生成 next 数组
void computeNext(char *pattern, int *next) {
    int m = strlen(pattern);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < m) {
        if (k == -1 || pattern[j] == pattern[k]) {
            ++j;
            ++k;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

// 计算转移函数
void computeDelta(char *pattern, int *delta) {
    int m = strlen(pattern);
    int next[m + 1];
    computeNext(pattern, next);

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < ALPHABET_SIZE; ++j) {
            delta[i * ALPHABET_SIZE + j] = 0;
        }
    }

    for (int x = 0; x <= m; ++x) {
        for (int c = 0; c < ALPHABET_SIZE; ++c) {
            char ch = 'a' + c;
            int new_x = x;
            while (new_x > 0 && pattern[new_x] != ch) {
                new_x = next[new_x];
            }
            if (pattern[new_x] == ch) {
                new_x++;
            }
            delta[x * ALPHABET_SIZE + c] = new_x;
        }
    }
}

int main() {
    char P[305];
    scanf("%s", P);
    int n = strlen(P);
    int delta[(n + 1) * ALPHABET_SIZE];
    computeDelta(P, delta);

    long long sum = 0;
    for (int x = 0; x <= n; ++x) {
        for (int c = 0; c < ALPHABET_SIZE; ++c) {
            sum += delta[x * ALPHABET_SIZE + c];
        }
    }

    printf("%lld\n", sum);
    return 0;
}