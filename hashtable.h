#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include "node.h"

typedef struct HashTable {
    LinkedList** table;
    size_t       size;
} HashTable;

HashTable* CreateHashTable(size_t s);
int        hash(char* hashable, int has_size);
int        ht_insert(HashTable* ht, char* key, char* val);
void       ht_display(HashTable* ht);
char*      ht_get(HashTable* ht, char* key);

#endif // HASHTABLE_H
