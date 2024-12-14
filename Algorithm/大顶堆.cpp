#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void insert(int arr[], int *n, int key) {
    *n = *n + 1;
    int i = *n - 1;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteRoot(int arr[], int *n) {
    if (*n == 0)
        return -1;

    int root = arr[0];
    arr[0] = arr[*n - 1];
    *n = *n - 1;
    heapify(arr, *n, 0);

    return root;
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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

    insert(arr, &n, 45);
    insert(arr, &n, 20);
    insert(arr, &n, 14);
    insert(arr, &n, 12);
    insert(arr, &n, 31);
    insert(arr, &n, 7);
    insert(arr, &n, 11);
    insert(arr, &n, 13);
    insert(arr, &n, 7);

    printf("Heap array:\n");
    printHeap(arr, n);

    printf("Deleted root: %d\n", deleteRoot(arr, &n));
    printHeap(arr, n);

    printf("Heap sort:\n");
    heapSort(arr, n);
    printHeap(arr, n);

    return 0;
}

