#include <stdio.h>
#include "node.h"

int main()
{
    char* mystring = "my string";
    Node* stringnode = CreateNode("my key", mystring, STRING);
    node_print(stringnode);
    printf("\n");

    node_update(stringnode, &(int){321321}, INT);
    node_print(stringnode);
    printf("\n");

    DestroyNode(stringnode);

    int myint = 215123;
    Node* intnode = CreateNode("my key", &myint, INT);
    node_print(intnode);
    printf("\n");

    node_update(intnode, &(int){11111}, INT);
    node_print(intnode);
    printf("\n");

    node_update(intnode, "int now string", STRING);
    node_print(intnode);
    printf("\n");

    DestroyNode(intnode);

    float myfloat = 124.2312;
    Node* floatnode = CreateNode("my key", &myfloat, FLOAT);
    node_print(floatnode);
    printf("\n");
    DestroyNode(floatnode);


    Node* intnode2 = CreateNode("my key", &(int){33}, INT);
    node_print(intnode2);
    printf("\n");
    DestroyNode(intnode2);

    Node* badnode = CreateNode("my key", &myint, 5);
    node_print(intnode);
    printf("\n");
    DestroyNode(intnode);

    return 0;
}
