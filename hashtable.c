#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "node.h"
#include "linkedlist.h"

HashTable* CreateHashTable(size_t size)
{
    HashTable* ht = malloc(sizeof(HashTable));
    ht->size      = size;
    ht->table     = calloc(size, sizeof(LinkedList));

    return ht;
}

int hash(char* hashable, int hash_size)
{
    int hashed = 0;
    for (int i=0; hashable[i] != 0; ++i) { hashed += hashable[i]; }
    return hashed % hash_size;
}

int ht_insert(HashTable* ht, char* key, char* val)
{
    int idx = hash(key, ht->size);
    if (ht->table[idx] == 0) { ht->table[idx] = CreateLinkedList(); }
    ll_append(ht->table[idx], CreateNode(key, val));
    return idx;
}


void ht_display(HashTable* ht)
{
    for (int i=0; i<ht->size; ++i)
    {
        printf("%2d: ", i);
        if (ht->table[i] != NULL)
            ll_display(ht->table[i]);
        else
            printf("\n");
    }
}

char* ht_get(HashTable* ht, char* key)
{
    int idx = hash(key, ht->size);
    return (ht->table[idx] == NULL) ? 0 : ll_search(ht->table[idx], key);
}

