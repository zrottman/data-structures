#include "Dictionary.h"

Dictionary* CreateDictionary(size_t capacity)
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

int dictionary_set(Dictionary* dict, char* key, void* val, DataType val_type)
{
    int idx = hash(key, dict->capacity);
    if (dict->table[idx] == 0) { dict->table[idx] = CreateLinkedList(); }
    ll_update_or_insert(dict->table[idx], key, val, val_type);
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

Node* dictionary_get(Dictionary* dict, char* key)
{
    int idx = hash(key, dict->capacity);
    return (dict->table[idx] == NULL) ? 0 : ll_get(dict->table[idx], key);
}

