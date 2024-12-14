#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//对数组元素进行了交换
//数组元素可能是奇怪的数
void reverse_bits(int *array, int n) {
    int max_bits = 0;
    int temp_n = n;
    while (temp_n >>= 1) {
        max_bits++;
    }

    for (int i = 0; i < n; i++) {
        int j = i;
        int reversed_i = 0;
        for (int k = 0; k < max_bits; k++) {
            reversed_i = (reversed_i << 1) | (j & 1);
            j >>= 1;
        }

        if (i < reversed_i) {
            int temp = array[i];
            array[i] = array[reversed_i];
            array[reversed_i] = temp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    reverse_bits(array, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}