#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linkedlist.h"
#include "queue.h"

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

    return 0;
}
