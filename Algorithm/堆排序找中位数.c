#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push_max_heap(int *heap, int *size, int value) {
    heap[++(*size)] = value;
    int current = *size;
    while (current > 1 && heap[current / 2] < heap[current]) {
        swap(&heap[current], &heap[current / 2]);
        current /= 2;
    }
}

void push_min_heap(int *heap, int *size, int value) {
    heap[++(*size)] = value;
    int current = *size;
    while (current > 1 && heap[current / 2] > heap[current]) {
        swap(&heap[current], &heap[current / 2]);
        current /= 2;
    }
}

int pop_max_heap(int *heap, int *size) {
    int result = heap[1];
    heap[1] = heap[*size];
    (*size)--;
    int current = 1;
    while (current * 2 <= *size) {
        int child = current * 2;
        if (child < *size && heap[child] < heap[child + 1]) {
            child++;
        }
        if (heap[current] >= heap[child]) {
            break;
        }
        swap(&heap[current], &heap[child]);
        current = child;
    }
    return result;
}

int pop_min_heap(int *heap, int *size) {
    int result = heap[1];
    heap[1] = heap[*size];
    (*size)--;
    int current = 1;
    while (current * 2 <= *size) {
        int child = current * 2;
        if (child < *size && heap[child] > heap[child + 1]) {
            child++;
        }
        if (heap[current] <= heap[child]) {
            break;
        }
        swap(&heap[current], &heap[child]);
        current = child;
    }
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int max_heap[100010], min_heap[100010];
        int max_heap_size = 0, min_heap_size = 0;
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            if (max_heap_size == 0 || num <= max_heap[1]) {
                push_max_heap(max_heap, &max_heap_size, num);
            } else {
                push_min_heap(min_heap, &min_heap_size, num);
            }
            // Balance heaps
            if (max_heap_size > min_heap_size + 1) {
                push_min_heap(min_heap, &min_heap_size, pop_max_heap(max_heap, &max_heap_size));
            } else if (min_heap_size > max_heap_size) {
                push_max_heap(max_heap, &max_heap_size, pop_min_heap(min_heap, &min_heap_size));
            }
            // Output median
            if ((i + 1) % 2 == 1) {
                if (max_heap_size > min_heap_size) {
                    printf("%d ", max_heap[1]);
                } else {
                    printf("%d ", (max_heap[1] + min_heap[1]) / 2);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
