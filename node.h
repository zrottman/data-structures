#ifndef NODE_H
#define NODE_H

typedef struct Node {
    char*       key;
    char*       val;
    struct Node *next;
} Node;

Node* CreateNode(char* key, char* val);
void  DestroyNode(Node* n);

#endif // NODE_H
