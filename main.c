#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linkedlist.h"
#include "queue.h"


typedef struct HashTable {
    LinkedList** hashtable;
    size_t       size;
} HashTable;

HashTable* ht_new(size_t size)
{
    HashTable *ht;
    ht = malloc(sizeof(HashTable));
    ht->hashtable = calloc(size, sizeof(LinkedList*));
    ht->size = size;
    return ht;

}

/*
void ht_display(HashTable *h)
{
    for (int i=0; i<h->size; ++i) {
        printf("%2d: ", i);
        if (h[i] != NULL)
            ll_display(h[i]);
    }

}
*/



int main() {

    /* queue test */
    Queue *q;

    q = q_new();
    printf("enqueing... new length: %d\n", q_enqueue(q, n_new(56)));
    printf("enqueing... new length: %d\n", q_enqueue(q, n_new(41)));
    printf("enqueing... new length: %d\n", q_enqueue(q, n_new(4)));
    printf("enqueing... new length: %d\n", q_enqueue(q, n_new(92)));
    printf("enqueing... new length: %d\n", q_enqueue(q, n_new(6)));
    q_display(q);

    Node *n;

    n = q_dequeue(q);
    printf("dequeued: %d\n", n->value);
    free(n);
    q_display(q);

    n = q_dequeue(q);
    printf("dequeued: %d\n", n->value);
    free(n);
    q_display(q);
    n = q_dequeue(q);
    printf("dequeued: %d\n", n->value);
    free(n);
    q_display(q);
    printf("enqueing... new length: %d\n", q_enqueue(q, n_new(41)));
    printf("enqueing... new length: %d\n", q_enqueue(q, n_new(4)));
    q_display(q);
    n = q_dequeue(q);
    printf("dequeued: %d\n", n->value);
    free(n);
    q_display(q);
    n = q_dequeue(q);
    printf("dequeued: %d\n", n->value);
    free(n);
    q_display(q);

    q_delete(q);

    /* hash table */
    LinkedList* hashtable[10] = { 0 };
    int nums[] = { 1, 5, 2, 7, 3, 2, 5, 3, 4, 7, 3, 4 };
    int num;

    for (int i=0; i<(sizeof(nums) / sizeof(nums[0])); ++i) {
        num = nums[i];
        if (hashtable[num] == NULL)
            hashtable[num] = ll_new();
        ll_append(hashtable[num], n_new(num));
    }

    for (int i=0; i<10; ++i) {
        printf("%2d: ", i);
        if (hashtable[i] != NULL) 
            ll_display(hashtable[i]);
        else
            printf("\n");
    }

    HashTable *hashtable2;
    hashtable2 = ht_new(10);

    for (int i=0; i<(sizeof(nums) / sizeof(nums[0])); ++i) {
        num = nums[i];
        ht_insert(hashtable2, n_new(num));
        if (hashtable2[num] == NULL)
            hashtable[num] = ll_new();
        ll_append(hashtable[num], n_new(num));
    }

    //ht_display(hashtable);





    return 0;
}
