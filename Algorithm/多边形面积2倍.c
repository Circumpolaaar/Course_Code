#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long x;
    long long y;
} Point;

long long polygonArea(Point *p, int n) {
    long long area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n; // 下一个点的索引，如果是最后一个点则回到第一个点
        area += p[i].x * p[j].y;
        area -= p[j].x * p[i].y;
    }
    //return llabs(area)/2; //返回多边形面积
    return llabs(area); // 不需要除以2，因为题目要求输出面积的两倍
}

int main() {
    int n;
    scanf("%d", &n);
    Point *points = (Point *)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &points[i].x, &points[i].y);
    }
    long long area = polygonArea(points, n);
    printf("%lld\n", area); // 直接输出area，因为polygonArea函数已经计算了面积的两倍

    free(points); // 释放分配的内存
    return 0;
}
