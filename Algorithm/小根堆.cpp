#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void insertMinHeap(int arr[], int *n, int key) {
    *n = *n + 1;
    int i = *n - 1;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteMinRoot(int arr[], int *n) {
    if (*n == 0)
        return -1;

    int minRoot = arr[0];
    arr[0] = arr[*n - 1];
    *n = *n - 1;
    minHeapify(arr, *n, 0);

    return minRoot;
}

void heapSortMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[20];
    int n = 0;

    insertMinHeap(arr, &n, 45);
    insertMinHeap(arr, &n, 20);
    insertMinHeap(arr, &n, 14);
    insertMinHeap(arr, &n, 12);
    insertMinHeap(arr, &n, 31);
    insertMinHeap(arr, &n, 7);
    insertMinHeap(arr, &n, 11);
    insertMinHeap(arr, &n, 13);
    insertMinHeap(arr, &n, 7);

    printf("Min Heap array:\n");
    printHeap(arr, n);

    printf("Deleted min root: %d\n", deleteMinRoot(arr, &n));
    printHeap(arr, n);

    printf("Heap sort (min heap):\n");
    heapSortMinHeap(arr, n);
    printHeap(arr, n);

    return 0;
}

