#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node* n_new(int val)
{
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->value = val;
    new_node->next  = NULL;
    return new_node;
}
