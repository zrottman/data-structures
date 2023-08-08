#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linkedlist.h"
#include "queue.h"


int main() {

    /* queue test */
    Queue *q;

    q = CreateQueue();
    printf("enqueing... new length: %d\n", q_enqueue(q, CreateNode("56", "57")));
    printf("enqueing... new length: %d\n", q_enqueue(q, CreateNode("41", "42")));
    printf("enqueing... new length: %d\n", q_enqueue(q, CreateNode("4", "5")));
    printf("enqueing... new length: %d\n", q_enqueue(q, CreateNode("92", "93")));
    printf("enqueing... new length: %d\n", q_enqueue(q, CreateNode("6", "7")));
    q_display(q);

    Node *n;

    n = q_dequeue(q);
    printf("dequeued: %s\n", n->val);
    free(n);
    q_display(q);

    n = q_dequeue(q);
    printf("dequeued: %s\n", n->val);
    free(n);
    q_display(q);
    n = q_dequeue(q);
    printf("dequeued: %s\n", n->val);
    free(n);
    q_display(q);
    printf("enqueing... new length: %d\n", q_enqueue(q, CreateNode("41", "42")));
    printf("enqueing... new length: %d\n", q_enqueue(q, CreateNode("4", "5")));
    q_display(q);
    n = q_dequeue(q);
    printf("dequeued: %s\n", n->val);
    free(n);
    q_display(q);
    n = q_dequeue(q);
    printf("dequeued: %s\n", n->val);
    free(n);
    q_display(q);

    q_delete(q);

    return 0;
}
