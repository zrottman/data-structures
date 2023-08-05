#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "node.h"

LinkedList* new_linkedlist(void)
{
    LinkedList* linkedlist;
    linkedlist = (LinkedList*)malloc(sizeof(LinkedList));
    linkedlist->head = NULL;
    linkedlist->tail = NULL;
    linkedlist->len  = 0;
    return linkedlist;
}

void append(LinkedList *list, Node *new_node)
{
    if (list->tail == 0) {
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = list->tail->next;
    }
    list->len++;
}

void display(LinkedList *list)
{
    Node* cur;
    for (cur = list->head; cur != NULL; cur = cur->next)
        printf("%d -> ", cur->value);
    printf("\n");
}

int delete_node(LinkedList *list, int target)
{
    Node *cur, *tmp;

    for (cur = list->head; cur != NULL; cur = cur->next) {
        if (cur->value == target) {
            list->head = list->head->next;
            list->len--;
            free(cur);
            return 0;
        } else if (cur->next != NULL && cur->next->value == target) {
            tmp = cur->next;
            cur->next = cur->next->next;
            list->len--;
            free(tmp);
            return 0;
        }
    }
    return -1;
}

int search(LinkedList *list, int target)
{
    Node *cur;
    int  idx = 0;

    for (cur = list->head; cur != NULL; cur = cur->next) {
        if (cur->value == target) { return idx; }
        idx++;
    }

    return -1;
}

void delete_list(LinkedList *list) 
{
    Node *cur = list->head;
    Node *tmp;

    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    free(list);
}
