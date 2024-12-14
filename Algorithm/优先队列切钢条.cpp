#include <iostream>
#include <queue>
#include <vector>

long long int minCostToCut(std::vector<long long int>& lengths) {
    // ʹ�����ȶ��У���С�ѣ����洢�����ĳ���
    std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int> > pq(lengths.begin(), lengths.end());

    long long int cost = 0;
    // ÿ�δ����ȶ�����ȡ��������С��Ԫ��
    // �����иȻ��Ż��и��ĳ���
    while (pq.size() > 1) {
        long long int first = pq.top(); pq.pop();
        long long int second = pq.top(); pq.pop();
        cost += 2 * (first + second); // �����и����
        pq.push(first + second); // ���и��ĳ��ȷŻ����ȶ���
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

