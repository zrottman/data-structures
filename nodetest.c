#include <stdio.h>
#include "node.h"

int main()
{
    char* mystring = "my string";
    Node* stringnode = CreateNode("my key", STRING, mystring);
    n_display(stringnode);
    DestroyNode(stringnode);

    int myint = 215123;
    Node* intnode = CreateNode("my key", INT, &myint);
    n_display(intnode);
    DestroyNode(intnode);

    return 0;
}
