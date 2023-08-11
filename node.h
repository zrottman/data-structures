#ifndef NODE_H
#define NODE_H

typedef enum DataType { STRING, INT, FLOAT } DataType;

typedef union Value {
    char* s;
    int   i;
    float f;
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

Node* CreateNode(char* key, void* val, DataType val_type);
void  DestroyNode(Node* n);
void  node_print(Node* n);
void  node_update(Node* n, void* val, DataType val_type);

#endif // NODE_H
