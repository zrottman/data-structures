#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int  len;
} LinkedList;

LinkedList  *ll_new(void);
void        ll_append(LinkedList *list, Node *new_node);
void        ll_display(LinkedList *list);
int         ll_delete_node(LinkedList *list, int target);
int         ll_search(LinkedList *list, int target);
void        ll_delete(LinkedList *list);

#endif // LINKEDLIST_H
