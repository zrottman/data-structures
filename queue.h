#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

typedef struct Queue {
    Node *head;
    Node *tail;
    int  len;
} Queue;

Queue*  q_new(void);
int     q_enqueue(Queue *q, Node *n);
Node*   q_dequeue(Queue *q);
void    q_display(Queue *q);
void    q_delete(Queue *q);

#endif // QUEUE_H
