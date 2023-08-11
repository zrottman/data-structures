#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "node.h"

LinkedList* CreateLinkedList(void)
{
    LinkedList* linkedlist = (LinkedList*)malloc(sizeof(LinkedList));
    linkedlist->head = NULL;
    linkedlist->tail = NULL;
    linkedlist->len  = 0;

    return linkedlist;
}

size_t ll_append(LinkedList *ll, char* key, void* val, DataType val_type)
{
    Node *n = CreateNode(key, val, val_type);
    if (ll->tail == 0) {
        ll->head = ll->tail = n;
    } else {
        ll->tail->next = n;
        ll->tail = ll->tail->next;
    }
    return ++ll->len;
}

size_t ll_update_or_insert(LinkedList *ll, char* key, void* val, DataType val_type)
{
    for (Node *cur = ll->head; cur != NULL; cur = cur->next) {
        if (strcmp(cur->key, key) == 0) {
            node_update(cur, val, val_type);
            return ll->len;
        }
    }
    return ll_append(ll, key, val, val_type);
}

void ll_display(LinkedList *ll)
{
    for (Node* cur = ll->head; cur != NULL; cur = cur->next) {
        node_print(cur);
        printf(" -> ");
    }
    printf("\n");
}

int ll_delete_node(LinkedList *ll, char* target)
{
    Node *tmp;

    // check for match at head
    if (strcmp(ll->head->key, target) == 0) {
        tmp = ll->head;
        ll->head = ll->head->next;
        ll->len--;
        DestroyNode(tmp);
        return 0;
    }

    // else iterate through ll
    for (Node* cur = ll->head; cur != NULL; cur = cur->next) {
        if (cur->next != NULL && (strcmp(cur->next->key, target) == 0)) {
            tmp = cur->next;
            cur->next = cur->next->next;
            ll->len--;
            DestroyNode(tmp);
            return 0;
        }
    }

    return -1;
}

int ll_search(LinkedList *ll, char* target)
{
    for (Node* cur = ll->head; cur != NULL; cur = cur->next)
        if (strcmp(cur->key, target) == 0) { return 0; }

    return -1;
}

Node* ll_get(LinkedList *ll, char* target)
{
    for (Node* cur = ll->head; cur != NULL; cur = cur->next)
        if (strcmp(cur->key, target) == 0) { return cur; }

    return NULL;

}

void DestroyLinkedList(LinkedList *ll) 
{
    Node *cur = ll->head;
    Node *tmp;

    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        DestroyNode(tmp);
    }

    free(ll);
}
