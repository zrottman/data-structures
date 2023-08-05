#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int  len;
} LinkedList;

LinkedList  *new_linkedlist(void);
void        append(LinkedList *list, Node *new_node);
void        display(LinkedList *list);
int         delete_node(LinkedList *list, int target);
int         search(LinkedList *list, int target);
void        delete_list(LinkedList *list);

#endif // LINKEDLIST_H
