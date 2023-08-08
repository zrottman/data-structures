#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int  len;
} LinkedList;

LinkedList* CreateLinkedList(void);
void        DestroyLinkedList(LinkedList *ll);
int         ll_append(LinkedList *list, Node *new_node);
void        ll_display(LinkedList *list);
int         ll_delete_node(LinkedList *list, char* target);
int         ll_search(LinkedList *list, char* target);
void        ll_delete(LinkedList *list);

#endif // LINKEDLIST_H
