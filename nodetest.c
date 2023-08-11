#include <stdio.h>
#include "node.h"

int main()
{
    char* mystring = "my string";
    Node* stringnode = CreateNode("my key", STRING, mystring);
    node_print(stringnode);
    printf("\n");
    DestroyNode(stringnode);

    int myint = 215123;
    Node* intnode = CreateNode("my key", INT, &myint);
    node_print(intnode);
    printf("\n");
    DestroyNode(intnode);

    float myfloat = 124.2312;
    Node* floatnode = CreateNode("my key", FLOAT, &myfloat);
    node_print(floatnode);
    printf("\n");
    DestroyNode(floatnode);

    Node* intnode2 = CreateNode("my key", INT, &(int){33});
    node_print(intnode2);
    printf("\n");
    DestroyNode(intnode2);

    Node* badnode = CreateNode("my key", 5, &myint);
    node_print(intnode);
    printf("\n");
    DestroyNode(intnode);

    return 0;
}
