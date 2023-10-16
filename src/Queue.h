#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

typedef struct Queue {
    Node *head;
    Node *tail;
    int  len;
} Queue;

Queue*  CreateQueue(void);
void    DestroyQueue(Queue *q);
int     q_enqueue(Queue *q, char *key, void *val, DataType val_type);
Node*   q_dequeue(Queue *q);
void    q_display(Queue *q);

#endif // QUEUE_H
