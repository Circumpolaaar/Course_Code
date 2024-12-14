#include <stdio.h>
#include <string.h>

// 函数用于计算并输出字符串s的π函数值
void compute_pi(char *s) {
    int n = strlen(s);
    int pi[n]; // π数组（这里使用pi作为变量名以避免与数学中的π混淆）
    
    // 初始化π数组
    for (int i = 0; i < n; i++) {
        pi[i] = 0;
    }
    
    // 计算π数组的值
    int k = 0; // k表示当前最长相等前缀后缀的长度
    for (int i = 1; i < n; i++) {
        while (k > 0 && s[i] != s[k]) {
            k = pi[k - 1]; // 根据π数组的值回退k
        }
        if (s[i] == s[k]) {
            k++; // 找到匹配，增加k
        }
        pi[i] = k; // 记录π(i)的值
    }
    
    // 输出π数组的值
    for (int i = 0; i < n; i++) {
        printf("%d ", pi[i]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T); // 读取数据组数
    
    while (T--) {
        char s[100005]; // 假设字符串长度不超过10^5
        scanf("%s", s); // 读取字符串
        
        compute_pi(s); // 计算并输出π函数值
    }
    
    return 0;
}