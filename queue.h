#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

typedef struct Queue {
    Node *head;
    Node *tail;
    int  len;
} Queue;

Queue*  new_queue(void);
int     enqueue(Queue *q, Node *n);
Node*   dequeue(Queue *q);
void    display_queue(Queue *q);
void    delete_queue(Queue *q);

#endif // QUEUE_H
