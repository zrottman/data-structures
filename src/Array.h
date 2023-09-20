#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int    *items;
    size_t length;
    size_t capacity;
} Array;

void   array_init(Array *a, size_t cap);
void   array_resize(Array *a, size_t new_capacity);
size_t array_append(Array *a, int item);

#endif // ARRAY_H
