#ifndef NODE_H
#define NODE_H

typedef enum DataType { STRING, INT } DataType;

typedef union Value {
    char* s;
    int   i;
} Value;

typedef struct VariableData {
    Value    data;
    DataType type;
} VariableData;

typedef struct Node {
    char*        key;
    VariableData val;
    struct Node  *next;
} Node;

Node* CreateNode(char* key, DataType val_type, void* val);
void  DestroyNode(Node* n);
void  n_display(Node* n);

#endif // NODE_H
