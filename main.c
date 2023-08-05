#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linkedlist.h"
#include "queue.h"

int main() {

    /* linked list test */
    LinkedList *my_list;

    my_list = new_linkedlist();

    append(my_list, new_node(1));
    append(my_list, new_node(2));
    append(my_list, new_node(3));
    append(my_list, new_node(4));
    append(my_list, new_node(5));
    append(my_list, new_node(6));
    append(my_list, new_node(7));

    printf("my_list->head->value: %d\n", my_list->head->value);
    printf("my_list->tail->value: %d\n", my_list->tail->value);
    printf("my_list->len        : %d\n", my_list->len);

    display(my_list);

    printf("Search for 9: %d\n", search(my_list, 9));
    printf("Search for 4: %d\n", search(my_list, 4));
    printf("Search for 2: %d\n", search(my_list, 2));

    printf("Deleting 2  : %d\n", delete_node(my_list, 2));
    printf("Deleting 9  : %d\n", delete_node(my_list, 9));

    display(my_list);

    printf("Search for 2: %d\n", search(my_list, 2));
    printf("my_list->len: %d\n", my_list->len);

    delete_list(my_list);

    /* queue test */
    Queue *q;

    q = new_queue();
    printf("enqueing... new length: %d\n", enqueue(q, new_node(56)));
    printf("enqueing... new length: %d\n", enqueue(q, new_node(41)));
    printf("enqueing... new length: %d\n", enqueue(q, new_node(4)));
    printf("enqueing... new length: %d\n", enqueue(q, new_node(92)));
    printf("enqueing... new length: %d\n", enqueue(q, new_node(6)));
    display_queue(q);

    Node *n;

    n = dequeue(q);
    printf("dequeued: %d\n", n->value);
    free(n);
    display_queue(q);

    n = dequeue(q);
    printf("dequeued: %d\n", n->value);
    free(n);
    display_queue(q);
    n = dequeue(q);
    printf("dequeued: %d\n", n->value);
    free(n);
    display_queue(q);
    printf("enqueing... new length: %d\n", enqueue(q, new_node(41)));
    printf("enqueing... new length: %d\n", enqueue(q, new_node(4)));
    display_queue(q);
    n = dequeue(q);
    printf("dequeued: %d\n", n->value);
    free(n);
    display_queue(q);
    n = dequeue(q);
    printf("dequeued: %d\n", n->value);
    free(n);
    display_queue(q);

    delete_queue(q);

    return 0;
}
