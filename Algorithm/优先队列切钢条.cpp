#include <iostream>
#include <queue>
#include <vector>

long long int minCostToCut(std::vector<long long int>& lengths) {
    // 使用优先队列（最小堆）来存储钢条的长度
    std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int> > pq(lengths.begin(), lengths.end());

    long long int cost = 0;
    // 每次从优先队列中取出两个最小的元素
    // 进行切割，然后放回切割后的长度
    while (pq.size() > 1) {
        long long int first = pq.top(); pq.pop();
        long long int second = pq.top(); pq.pop();
        cost += 2 * (first + second); // 计算切割费用
        pq.push(first + second); // 将切割后的长度放回优先队列
    }
    return cost;
}

int main() {
    int n;
    scanf("%d", &n);

    std::vector<long long int> lengths(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &lengths[i]);
    }

    long long int totalCost = minCostToCut(lengths);
    printf("%lld\n", totalCost);

    return 0;
}

