#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

Array* array_construct(size_t cap) {
    Array *a    = malloc(sizeof(Array));
    if (a == NULL) {
        // handle
    }
    a->length   = 0;
    a->capacity = cap;
    a->items    = calloc(cap, sizeof(int));
    if (a->items == NULL) {
        //handle
    }
    return a;
}

void array_destroy(Array** a) {
    free((*a)->items);
    (*a)->items = NULL;
    free(*a);
    (*a) = NULL;
}

void array_resize(Array *a, size_t new_capacity) {

    printf("Resizing array: %zu -> %zu\n", a->capacity, new_capacity);
    
    int *items = calloc(new_capacity, sizeof(int));
    if (items == NULL) {
        // handle
    }
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

    return ++a->length; // return new length
}

int array_get(Array *a, size_t idx) {
    if (idx < 0 || idx >= a->length) {
        // error
    }
    return a->items[idx];
}

void array_display(Array *a) {
    printf("[");
    for (int i=0; i<a->length; ++i) {
        printf("%d", a->items[i]);
        if (i == a->length - 1) {
            printf("]");
            continue;
        }
        printf(", ");
    }
    printf("\n");
}
