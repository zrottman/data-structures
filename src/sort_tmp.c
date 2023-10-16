#include <stdlib.h>

void _merge_sort_helper(int* arr, size_t low, size_t high)
{
    if (high <= low) { return; }

    _merge_sort_helper(arr, low, (high + low) / 2);
    _merge_sort_helper(arr, (high + low) / 2 + 1, high);

    size_t mid = (high + low) / 2;
    size_t idx_one = low;
    size_t idx_two = mid + 1;
    size_t i = 0;
    int *tmp = calloc(high - low + 1, sizeof(int));

    while (idx_one <= mid && idx_two <= high) {
        tmp[i++] = arr[idx_one] < arr[idx_two] ? arr[idx_one++] : arr[idx_two++];
    }

    while (idx_one <= mid) {
        tmp[i++] = arr[idx_one++];
    }

    while (idx_two <= high) {
        tmp[i++] = arr[idx_two++];
    }

    for (size_t i=0; i<high-low+1; ++i) {
        arr[i+low] = tmp[i];
    }

    free(tmp);
}

void merge_sort(int* arr, size_t length) {
    _merge_sort_helper(arr, 0, length-1);
}
