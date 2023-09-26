#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

void array_init(Array *a, size_t cap) {
    a->length   = 0;
    a->capacity = cap;
    a->items    = calloc(cap, sizeof(int));
    return;
}

void array_resize(Array *a, size_t new_capacity) {

    printf("Resizing array: %zu -> %zu\n", a->capacity, new_capacity);
    
    int *items = calloc(new_capacity, sizeof(int));
    for (int i=0; i<a->length; ++i)
        items[i] = a->items[i];
    free(a->items);
    a->capacity = new_capacity;
    a->items    = items;

    return;
}

size_t array_append(Array *a, int item) {
    if (a->length == a->capacity)
        array_resize(a, a->capacity * 2);
    a->items[a->length] = item;

    return ++a->length;
}

