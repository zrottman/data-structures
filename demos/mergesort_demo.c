#include <stdio.h>
#include "../src/sort.h"

int main() {
    int arr[10] = {1, 5, 8, 32, 9, 0, 2, 3, 13, 14};

    for (int i=0; i<10; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    merge_sort(arr, 10);
    for (int i=0; i<10; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
