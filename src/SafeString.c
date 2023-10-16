#include "SafeString.h"

struct string_t* string_create(size_t capacity) {
    struct string_t* str = malloc(sizeof(struct string_t));

    if (!str) {
        return NULL; // malloc failure
    }

    str->buf = malloc(capacity);
    if (!str->buf) {
        free(str);
        return NULL; // malloc failure
    }

    str->len    = 0;
    str->cap    = capacity;
    str->buf[0] = '\0';

    return str;
}

int string_destroy(struct string_t** str) {
    if (*str) {
        if ((*str)->buf) {
            free((*str)->buf);
            (*str)->buf = NULL;
        }
        free(*str);
        (*str) = NULL;
    }
    return 0;
}

int string_set(struct string_t* dest, const char* src) {
    size_t src_len = strlen(src); // strlen does not include null byte
    if (src_len >= dest->cap) {
        return 1; // insufficient space
    }

    strcpy(dest->buf, src); // strcpy does include null byte
    dest->len = src_len;
    return 0;
}

int string_appendc(struct string_t* str, const char c) {
    if (str->len + 1 == str->cap) {
        return 1; // not enough space
    }
    str->buf[str->len++] = c;
    str->buf[str->len] = 0;
    return 0;
}

