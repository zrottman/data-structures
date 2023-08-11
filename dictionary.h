#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include "node.h"

typedef struct Dictionary {
    LinkedList** table;
    size_t       capacity;
} Dictionary;

Dictionary* CreateDictionary(size_t s);
void        DestroyDictionary(Dictionary* h);
int         hash(char* hashable, int hash_size);
int         dictionary_set(Dictionary* dict, char* key, void* val, DataType val_type);
void        dictionary_display(Dictionary* dict);
Node*       dictionary_get(Dictionary* dict, char* key);

#endif // HASHTABLE_H
