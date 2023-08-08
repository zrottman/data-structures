#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "node.h"

Queue* CreateQueue(void)
{
    Queue *q;
    q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->len  = 0;
    return q;
}

int q_enqueue(Queue* q, Node *n)
{
    if (q->tail == NULL) {
        q->head = q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = q->tail->next;
    }
    return ++q->len;
}

Node* q_dequeue(Queue* q)
{
    Node *tmp;
    if (q->head != NULL) {
        tmp = q->head;
        q->head = q->head->next;
        q->len--;
    }
    return tmp;
}

void q_display(Queue *q)
{
    for(Node* cur=q->head; cur != NULL; cur=cur->next)
        printf("%s/%s -> ", cur->key, cur->val);
    printf("\n");
}

void DestroyQueue(Queue *q)
{
    Node *cur = q->head;
    Node *tmp;

    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        DestroyNode(tmp);
    }

    free(q);
}
