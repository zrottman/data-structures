#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linkedlist.h"
#include "queue.h"


int main() {

    /* queue test */
    Queue *q;

    q = CreateQueue();
    printf("enqueing... new length: %d\n", q_enqueue(q, "hi", "hola", STRING));
    printf("enqueing... new length: %d\n", q_enqueue(q, "33", &(int){33}, INT));
    printf("enqueing... new length: %d\n", q_enqueue(q, "pi", &(float){3.14}, FLOAT));
    printf("enqueing... new length: %d\n", q_enqueue(q, "bye", "adios", STRING));
    printf("enqueing... new length: %d\n", q_enqueue(q, "4321", &(int){4321}, INT));
    q_display(q);

    Node *n;

    n = q_dequeue(q);
    printf("dequeued: ");
    node_print(n);
    printf("\n");
    free(n);

    q_display(q);

    n = q_dequeue(q);
    printf("dequeued: ");
    node_print(n);
    printf("\n");
    free(n);

    q_display(q);

    n = q_dequeue(q);
    printf("dequeued: ");
    node_print(n);
    printf("\n");
    free(n);

    q_display(q);

    printf("enqueing... new length: %d\n", q_enqueue(q, "hello", "hallo", STRING));
    printf("enqueing... new length: %d\n", q_enqueue(q, "2468", &(int){2468}, INT));

    q_display(q);

    n = q_dequeue(q);
    printf("dequeued: ");
    node_print(n);
    printf("\n");
    free(n);

    q_display(q);

    n = q_dequeue(q);
    printf("dequeued: ");
    node_print(n);
    printf("\n");
    free(n);
    q_display(q);

    DestroyQueue(q);

    return 0;
}
