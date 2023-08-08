#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include "node.h"

typedef struct HashTable {
    LinkedList *table;
} HashTable;

//HashTable*  ht_new(int size);
void        ht_init(HashTable* h);
int         ht_insert(HashTable* h, Node *n);
Node*       ht


#endif // HASHTABLE_H
