#include <stdio.h>

// 递归实现的GCD函数
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd_recursive(b, a % b);
    }
}
// 迭代实现的GCD函数
int gcd_iterative(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("The GCD of %d and %d is %d\n", num1, num2, gcd_recursive(num1, num2));
    printf("The GCD of %d and %d is %d\n", num1, num2, gcd_iterative(num1, num2));
    return 0;
}