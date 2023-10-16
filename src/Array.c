#include "Array.h"

Array* array_construct(size_t cap) {
    Array *a    = malloc(sizeof(Array));

    // handle struct allocation error
    if (a == NULL) {
        return NULL;
    }

    a->length   = 0;
    a->capacity = cap;
    a->items    = calloc(cap, sizeof(int));

    // handle array allocation error
    if (a->items == NULL) {
        free(a);
        return NULL;
    }

    return a;
}

void array_destroy(Array** a) {
    // free array and point to NULL
    free((*a)->items);
    (*a)->items = NULL;
    // free struct and point to NULL
    free(*a);
    (*a) = NULL;
}

void array_resize(Array *a, size_t new_capacity) {

    int *new_items = calloc(new_capacity, sizeof(int));

    if (new_items == NULL) {
        // handle
    }

    // copy items from old to new
    for (int i=0; i<a->length; ++i) { new_items[i] = a->items[i]; }
    
    // free old array
    free(a->items);

    // update capacity and copy new_items
    a->capacity = new_capacity;
    a->items    = new_items;

    return;
}

size_t array_append(Array *a, int item) {
    // double array if at capacity
    if (a->length == a->capacity) {
        array_resize(a, a->capacity * 2);
    }

    // add item to next available idx
    a->items[a->length] = item;

    // return new length of array
    return ++a->length;
}

int array_get(Array *a, size_t idx) {
    if (idx < 0 || idx >= a->length) {
        // error
    }
    return a->items[idx];
}

void array_display(Array *a) {
    for (int i=0; i<a->length; ++i) {
        if (i == 0) {
            printf("[");
        }
        printf("%d", a->items[i]);
        if (i == a->length - 1) {
            printf("]");
        } else {
            printf(", ");
        }
    }
    printf("\n");
}
