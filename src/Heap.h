#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "Array.h"

#define DEFAULT_HEAP_SIZE 8
#define EMPTY_HEAP_SENTINEL INT_MIN
#define HEAP_EMPTY_ERROR -1
#define SUCCESS 0

typedef enum HeapType { MAX, MIN } HeapType;

Array*  heap_construct(void);
void   heap_destroy(Array** h);
void   heap_swap(Array *h, size_t idx_one, size_t idx_two);

size_t get_parent_idx(size_t child_idx);
size_t get_left_child_idx(size_t parent_idx);
size_t get_right_child_idx(size_t parent_idx);

bool   has_parent(Array* h, size_t child_idx);
bool   has_left_child(Array* h, size_t parent_idx);
bool   has_right_child(Array* h, size_t parent_idx);

int    get_parent(Array* h, size_t child_idx);
int    get_left_child(Array* h, size_t parent_idx);
int    get_right_child(Array* h, size_t parent_idx);

size_t heap_insert(Array* h, int val);
size_t heapify_up(Array *h, size_t idx);
size_t heapify_down(Array *h, size_t idx);
int    poll(Array *h, int *res);
void   heap_display(Array* h);

#endif // HEAP_H
