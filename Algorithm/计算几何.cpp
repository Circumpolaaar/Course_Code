#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <cassert>
// 定义点的结构体
typedef struct {
    double x, y;
} Point;

//P1P2叉乘P3P4
double chacheng(Point p1,Point p2,Point p3,Point p4){
     return (p2.x-p1.x)*(p4.y-p3.y)-(p4.x-p3.x)*(p2.y-p1.y);
}

//P1P2点乘P3P4
double diancheng(Point p1,Point p2,Point p3,Point p4){
    return (p2.x-p1.x)*(p4.x-p3.x)+(p2.y-p1.y)*(p4.y-p3.y);
}
//向量的模
double len(Point a){
    return sqrt(a.x * a.x + a.y * a.y);
}

// 计算两点之间的距离
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// 计算三角形外接圆圆心
Point circumcenter(Point p1,Point p2,Point p3) {
    double D = 2 * (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
    if (D == 0) {
        // 三点共线
        printf("Error\n");
        Point errorPoint = {-1, -1};
        return errorPoint;
    }
    double x = ((p1.x * p1.x + p1.y * p1.y) * (p2.y - p3.y) +
                (p2.x * p2.x + p2.y * p2.y) * (p3.y - p1.y) +
                (p3.x * p3.x + p3.y * p3.y) * (p1.y - p2.y)) / D;
    double y = ((p1.x * p1.x + p1.y * p1.y) * (p3.x - p2.x) +
                (p2.x * p2.x + p2.y * p2.y) * (p1.x - p3.x) +
                (p3.x * p3.x + p3.y * p3.y) * (p2.x - p1.x)) / D;
    Point center;
    center.x = x;
    center.y = y;
    return center;
}

// 计算三角形的内切圆圆心
Point incenter(Point p1,Point p2, Point p3) {
    double a = distance(p2, p3);
    double b = distance(p1, p3);
    double c = distance(p1, p2);
printf("%lf %lf %lf\n",a,b,c);
    double x = (a * p1.x + b * p2.x + c * p3.x) / (a + b + c);
    double y = (a * p1.y + b * p2.y + c * p3.y) / (a + b + c);

    Point incenter = {x, y};
    return incenter;
}

// 计算点到直线的距离
double pointToLineDistance(Point P0, Point P1, Point P2) {
     if (P1.x == P2.x && P1.y == P2.y) {
        // 直线退化成点
        printf("Error\n");
        return -1;
    }
    double A = P2.y - P1.y;
    double B = P1.x - P2.x;
    double C = P2.x * P1.y - P1.x * P2.y;
    
    // 使用点到直线的距离公式
    double distance = fabs(A * P0.x + B * P0.y + C) / sqrt(A * A + B * B);
    return distance;
}

//向量夹角
double Angle(Point p1,Point p2,Point p3,Point p4) {
    Point A,B;
    A.x=p2.x-p1.x;
    A.y=p2.y-p1.y;
    B.x=p4.x-p3.x;
    B.y=p4.y-p3.y;
    double t = acos((diancheng(p1,p2,p3,p4)) / len(A) / len(B));
    return t;               // 返回 [0, π]
    return t * (180 / 3.14159);  // 返回 [0, 180] (角度)
}

int main() {
    
    return 0;
}