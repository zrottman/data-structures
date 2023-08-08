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

    /* linked list test */
    LinkedList *my_list;

    my_list = ll_new();

    ll_append(my_list, n_new(1));
    ll_append(my_list, n_new(2));
    ll_append(my_list, n_new(3));
    ll_append(my_list, n_new(4));
    ll_append(my_list, n_new(5));
    ll_append(my_list, n_new(6));
    ll_append(my_list, n_new(7));

    printf("my_list->head->value: %d\n", my_list->head->value);
    printf("my_list->tail->value: %d\n", my_list->tail->value);
    printf("my_list->len        : %d\n", my_list->len);

    ll_display(my_list);

    printf("Search for 9: %d\n", ll_search(my_list, 9));
    printf("Search for 4: %d\n", ll_search(my_list, 4));
    printf("Search for 2: %d\n", ll_search(my_list, 2));

    printf("Deleting 2  : %d\n", ll_delete_node(my_list, 2));
    printf("Deleting 9  : %d\n", ll_delete_node(my_list, 9));

    ll_display(my_list);

    printf("Search for 2: %d\n", ll_search(my_list, 2));
    printf("my_list->len: %d\n", my_list->len);

    ll_delete(my_list);

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
