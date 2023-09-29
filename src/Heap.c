#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Heap.h"


Heap* heap_init(size_t capacity, HeapType type) {
    Heap* h = malloc(sizeof(Heap));

    h->items    = calloc(capacity + 1, sizeof(int));
    h->length   = 0;
    h->capacity = capacity;
    h->type     = type;

    return h;
}

void heap_destroy(Heap** h) {
    free((*h)->items);
    (*h)->items = NULL;
    free(*h);
    *h = NULL;
}

void heap_swap(Heap *h, size_t idx_one, size_t idx_two) {
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
bool has_parent(Heap* h, size_t child_idx) {
    size_t parent_idx = get_parent_idx(child_idx);
    return 0 <= parent_idx && parent_idx < h->length;
}

bool has_left_child(Heap* h, size_t parent_idx) {
    size_t left_child_idx = get_left_child_idx(parent_idx);
    return 0 <= left_child_idx && left_child_idx < h->length;
}

bool has_right_child(Heap* h, size_t parent_idx) {
    size_t right_child_idx = get_right_child_idx(parent_idx);
    return 0 <= right_child_idx && right_child_idx < h->length;
}

/* get parent/child value */
int get_parent(Heap* h, size_t child_idx) {
    return h->items[get_parent_idx(child_idx)];
}

int get_left_child(Heap* h, size_t parent_idx) {
    return h->items[get_left_child_idx(parent_idx)];
}

int get_right_child(Heap* h, size_t parent_idx) {
    return h->items[get_right_child_idx(parent_idx)];
}

size_t heap_insert(Heap* h, int val) {
    size_t idx;
    h->items[h->length] = val;
    idx = h->length;
    if (h->length < h->capacity) { h->length++; }
    idx = heapify_up(h, idx);
    idx = heapify_down(h, idx);
    return idx;
}

size_t heapify_up(Heap *h, size_t idx) {
    while (has_parent(h, idx) && h->items[idx] > get_parent(h, idx)) {
        heap_swap(h, idx, get_parent_idx(idx));
        idx = get_parent_idx(idx);
    }
    return idx;
}

size_t heapify_down(Heap *h, size_t idx) {
    while ((has_left_child(h, idx) && h->items[idx] < get_left_child(h, idx)) || (has_right_child(h, idx) && h->items[idx] < get_right_child(h, idx))) {
        // two children? swap with the bigger of the two
        if (has_left_child(h, idx) && has_right_child(h, idx)) {
            if (get_left_child(h, idx) < get_right_child(h, idx)) {
                heap_swap(h, idx, get_right_child_idx(idx));
                idx = get_right_child_idx(idx);
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

void heap_display(Heap* h) {
    for (int i=0; i<h->length; ++i) {
        printf("%d ", h->items[i]);
    }
    printf("\n");
}
