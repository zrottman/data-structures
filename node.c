#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node* new_node(int val)
{
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->value = val;
    return new_node;
}
