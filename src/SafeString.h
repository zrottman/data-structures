#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <string.h>

struct string_t {
    char*  buf;
    size_t len;
    size_t cap;
};

struct string_t* string_create(size_t capacity);
int              string_destroy(struct string_t** str);
int              string_set(struct string_t* dest, const char* src);
int              string_appendc(struct string_t* str, const char c);

#endif // STRING_H

