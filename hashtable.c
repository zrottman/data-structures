#include <stdlib.h>
#include "hashtable.h"

void ht_init(HashTable *h, int size) 
{
    h->table = (LinkedList*)calloc(1, size);
}



int ht_insert(HashTable *h, Node *n)
{
}
