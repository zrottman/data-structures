#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "Array.h"

#define DEFAULT_HEAP_SIZE 8
#define EMPTY_HEAP_SENTINEL INT_MIN
#define HEAP_EMPTY_ERROR -1
#define SUCCESS 0

typedef enum HeapType { MAX, MIN } HeapType;
typedef Array Heap;

Heap*  heap_construct(void);
void   heap_destroy(Heap** h);
void   heap_swap(Heap *h, size_t idx_one, size_t idx_two);

size_t get_parent_idx(size_t child_idx);
size_t get_left_child_idx(size_t parent_idx);
size_t get_right_child_idx(size_t parent_idx);

bool   has_parent(Heap* h, size_t child_idx);
bool   has_left_child(Heap* h, size_t parent_idx);
bool   has_right_child(Heap* h, size_t parent_idx);

int    get_parent(Heap* h, size_t child_idx);
int    get_left_child(Heap* h, size_t parent_idx);
int    get_right_child(Heap* h, size_t parent_idx);

size_t heap_insert(Heap* h, int val);
size_t heapify_up(Heap *h, size_t idx);
size_t heapify_down(Heap *h, size_t idx);
int    poll(Heap *h, int *res);
void   heap_display(Heap* h);

#endif // HEAP_H
