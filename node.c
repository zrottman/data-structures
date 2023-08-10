#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

Node* CreateNode(char* key, DataType val_type, void* val)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->key  = (char*)malloc(strlen(key) + 1); // strlen does not include null terminator
    strcpy(node->key, key); // strcpy includes null terminator
                            
    node->val.type = val_type;
    switch (val_type) {
        case STRING:
            node->val.data.s = (char*)malloc(strlen((char*)val) + 1);
            strcpy(node->val.data.s, (char*)val);
            break;
        case INT:
            node->val.data.i = *(int*)val;
            break;
    }

    node->next = NULL;

    return node;
}

void DestroyNode(Node* n)
{
    free(n->key);
    if (n->val.type == STRING)
        free(n->val.data.s);
    free(n);
}

void n_display(Node* n)
{
    printf("%s/", n->key);
    switch (n->val.type) {
        case STRING:
            printf("%s", n->val.data.s);
        case INT:
            printf("%d", n->val.data.i);
    }

}



