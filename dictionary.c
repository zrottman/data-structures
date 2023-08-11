#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include "node.h"
#include "linkedlist.h"

Dictionary* CreateHashTable(size_t capacity)
{
    Dictionary* dict = malloc(sizeof(Dictionary));
    dict->capacity  = capacity;
    dict->table     = calloc(capacity, sizeof(LinkedList*));

    return dict;
}

int hash(char* hashable, int hash_size)
{
    int hashed = 0;
    for (int i=0; hashable[i] != 0; ++i) { hashed += hashable[i]; }
    return hashed % hash_size;
}

int dictionary_insert(Dictionary* dict, char* key, char* val)
{
    // support for resetting val at key
    int idx = hash(key, dict->capacity);
    if (dict->table[idx] == 0) { dict->table[idx] = CreateLinkedList(); }
    ll_append(dict->table[idx], CreateNode(key, val));
    return idx;
}

void dictionary_display(Dictionary* dict)
{
    for (int i=0; i<dict->capacity; ++i) {
        printf("%2d: ", i);
        if (dict->table[i] != NULL)
            ll_display(dict->table[i]);
        else
            printf("\n");
    }
}

char* dictionary_get(Dictionary* dict, char* key)
{
    int idx = hash(key, dict->capacity);
    return (dict->table[idx] == NULL) ? 0 : ll_search(dict->table[idx], key);
}

