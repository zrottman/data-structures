#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Heap.h"
#include "Array.h"


Array* heap_construct(void) {
    Array *heap = array_construct(DEFAULT_HEAP_SIZE);
    return heap;
}

void heap_destroy(Array** h) {
    array_destroy(h);
}

void heap_swap(Array *h, size_t idx_one, size_t idx_two) {
    int tmp = h->items[idx_one];
    h->items[idx_one] = h->items[idx_two];
    h->items[idx_two] = tmp;
    return;
}

/* get parent/child index */
size_t get_parent_idx(size_t child_idx) {
    return (child_idx - 1) / 2;
}

size_t get_left_child_idx(size_t parent_idx) {
    return parent_idx * 2 + 1;
}

size_t get_right_child_idx(size_t parent_idx) {
    return parent_idx * 2 + 2;
}

/* has parent/child */
bool has_parent(Array* h, size_t child_idx) {
    size_t parent_idx = get_parent_idx(child_idx);
    return 0 <= parent_idx && parent_idx < h->length;
}

bool has_left_child(Array* h, size_t parent_idx) {
    size_t left_child_idx = get_left_child_idx(parent_idx);
    return 0 <= left_child_idx && left_child_idx < h->length;
}

bool has_right_child(Array* h, size_t parent_idx) {
    size_t right_child_idx = get_right_child_idx(parent_idx);
    return 0 <= right_child_idx && right_child_idx < h->length;
}

/* get parent/child value */
int get_parent(Array* h, size_t child_idx) {
    return h->items[get_parent_idx(child_idx)];
}

int get_left_child(Array* h, size_t parent_idx) {
    return h->items[get_left_child_idx(parent_idx)];
}

int get_right_child(Array* h, size_t parent_idx) {
    return h->items[get_right_child_idx(parent_idx)];
}

size_t heap_insert(Array* h, int val) {
    size_t idx;
    idx = array_append(h, val) - 1;
    idx = heapify_up(h, idx);
    idx = heapify_down(h, idx);
    return idx;
}

size_t heapify_up(Array *h, size_t idx) {
    while (has_parent(h, idx) && h->items[idx] > get_parent(h, idx)) {
        heap_swap(h, idx, get_parent_idx(idx));
        idx = get_parent_idx(idx);
    }
    return idx;
}

size_t heapify_down(Array *h, size_t idx) {
    while ((has_left_child(h, idx) && h->items[idx] < get_left_child(h, idx)) || (has_right_child(h, idx) && h->items[idx] < get_right_child(h, idx))) {
        // two children? swap with the bigger of the two
        if (has_left_child(h, idx) && has_right_child(h, idx)) {
            // swap right
            if (get_left_child(h, idx) < get_right_child(h, idx)) {
                heap_swap(h, idx, get_right_child_idx(idx));
                idx = get_right_child_idx(idx);
            // swap left
            } else {
                heap_swap(h, idx, get_left_child_idx(idx));
                idx = get_left_child_idx(idx);
            }
        // left child only? swap left
        } else {
            heap_swap(h, idx, get_left_child_idx(idx));
            idx = get_left_child_idx(idx);
        }
    }
    return idx;
}

int poll(Array *h, int *res) {
    if (h->length == 0) {
        *res = EMPTY_HEAP_SENTINEL;
        return HEAP_EMPTY_ERROR;
    }
    heap_swap(h, 0, --h->length);
    *res = h->items[h->length];
    heapify_down(h, 0);
    return SUCCESS;
}

void heap_display(Array* h) {
    array_display(h);
}
