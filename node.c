#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

Node* CreateNode(char* k, char* v)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->key  = (char*)malloc(strlen(k) + 1); // strlen does not include null terminator
    node->val  = (char*)malloc(strlen(v) + 1);
    node->next = NULL;

    strcpy(node->key, k); // strcpy includes null terminator
    strcpy(node->val, v);

    return node;
}

void DestroyNode(Node* n)
{
    free(n->key);
    free(n->val);
    free(n);
}

void n_display(Node* n)
{
    printf("%s/%s", n->key, n->val);
}
