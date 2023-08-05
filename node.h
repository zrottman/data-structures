#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int         value;
    struct Node *next;
} Node;

Node* n_new(int val);

#endif // NODE_H
