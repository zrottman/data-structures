#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

typedef struct Queue {
    Node *head;
    Node *tail;
    int  len;
} Queue;

Queue*  CreateQueue(void);
void    DeleteQueue(Queue *q);
int     q_enqueue(Queue *q, Node *n);
Node*   q_dequeue(Queue *q);
void    q_display(Queue *q);

#endif // QUEUE_H
