#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

Node* CreateNode(char* key, void* val, DataType val_type)
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
        case FLOAT:
            node->val.data.f = *(float*)val;
            break;
        default:
            printf("invalid type");
            DestroyNode(node);
            exit(EXIT_FAILURE);
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

void node_print(Node* n)
{
    printf("%s/", n->key);
    switch (n->val.type) {
        case STRING:
            printf("%s", n->val.data.s);
            break;
        case INT:
            printf("%d", n->val.data.i);
            break;
        case FLOAT:
            printf("%f", n->val.data.f);
            break;
        default:
            printf("invalid type");
            break;
    }

}

void  node_update(Node* n, void* val, DataType val_type)
{
    // currently only updates val/val_type
    if (n != NULL) {
        if (n->val.type == STRING) { free(n->val.data.s); }
        n->val.type = val_type;
        switch (val_type) {
            case STRING:
                n->val.data.s = (char*)malloc(strlen((char*)val) + 1);
                strcpy(n->val.data.s, (char*)val);
                break;
            case INT:
                n->val.data.i = *(int*)val;
                break;
            case FLOAT:
                n->val.data.f = *(float*)val;
                break;
        }

    }
}


