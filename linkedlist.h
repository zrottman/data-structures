#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

typedef struct LinkedList {
    Node*  head;
    Node*  tail;
    size_t len;
} LinkedList;

LinkedList* CreateLinkedList(void);
void        DestroyLinkedList(LinkedList *ll);
size_t      ll_append(LinkedList *list, char* key, void *val, DataType val_type);
void        ll_display(LinkedList *list);
int         ll_delete_node(LinkedList *list, char* target);
int         ll_search(LinkedList *list, char* target);

#endif // LINKEDLIST_H
