#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include "node.h"

typedef struct Dictionary {
    LinkedList** table;
    size_t       capacity;
} Dictionary;

Dictionary* CreateHashTable(size_t s);
void       DestroyHashTable(Dictionary* h);
int        hash(char* hashable, int hash_size);
int        dictionary_insert(Dictionary* dict, char* key, char* val);
void       dictionary_display(Dictionary* dict);
char*      dictionary_get(Dictionary* dict, char* key);

#endif // HASHTABLE_H
