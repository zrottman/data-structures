#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "node.h"

Queue* new_queue(void)
{
    Queue *q;
    q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->len  = 0;
    return q;
}

int enqueue(Queue* q, Node *n)
{
    if (q->tail == NULL) {
        q->head = q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = q->tail->next;
    }
    q->len++;
    return q->len;
}

Node* dequeue(Queue* q)
{
    Node *tmp;
    if (q->head != NULL) {
        tmp = q->head;
        q->head = q->head->next;
        q->len--;
    }
    return tmp;
}

void display_queue(Queue *q)
{
    Node *cur;
    for(cur=q->head; cur != NULL; cur=cur->next)
        printf("%d -> ", cur->value);
    printf("\n");
}

void delete_queue(Queue *q)
{
    Node *cur = q->head;
    Node *tmp;

    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    free(q);
}
