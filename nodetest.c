#include <stdio.h>
#include "node.h"


int main()
{
    Node* mynode = CreateNode("my key", "my val");
    printf("key: %s\n", mynode->key);
    printf("val: %s\n", mynode->val);

    DestroyNode(mynode);

    return 0;
}
