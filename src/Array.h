#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int    *items;
    size_t length;
    size_t capacity;
} Array;

Array* array_construct(size_t cap);
void   array_destroy (Array **a);
void   array_resize(Array *a, size_t new_capacity);
size_t array_append(Array *a, int item);
int    array_get(Array *a, size_t idx);
void   array_display(Array *a);

#endif // ARRAY_H
