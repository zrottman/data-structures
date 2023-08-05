#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int         value;
    struct Node *next;
} Node;

Node* new_node(int val);

#endif // NODE_H
