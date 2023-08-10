#include <stdio.h>
#include "hashtable.h"
#include "linkedlist.h"
#include "node.h"

int main()
{

    /* Node test */
    Node* mynode = CreateNode("Hello, World", "msg");

    printf("mynode->key: %s\n", mynode->key);
    printf("mynode->val: %s\n", mynode->val);
    printf("hashed @ 10: %d\n", hash(mynode->key, 10));

    /* Linked List test */
    LinkedList* mylist = CreateLinkedList();

    printf("list length: %zu\n", ll_append(mylist, mynode));
    printf("list length: %zu\n", ll_append(mylist, CreateNode("sup", "dude")));

    ll_display(mylist);

    /* Hash table test */
    Dictionary* dict = CreateHashTable(10);
    char *keys[] = {"hey", "sup", "morning", "goodbye", "there", "abcde", "cedba", "baedc"};
    char *vals[] = {"hola", "que pasa", "manana", "adios", "alli", "1", "2", "3"};

    for (int i=0; i<8; ++i)
    {
        printf("`%s` hashed to %d\n", keys[i], dictionary_insert(dict, keys[i], vals[i]));
    }

    dictionary_display(dict);

    char* target = "goodbye";
    printf("%s -> %s\n", target, dictionary_get(dict, target));
    char* target2 = "baedc";
    printf("%s -> %s\n", target2, dictionary_get(dict, target2));
    char* target3 = "sdfasdfa";
    printf("%s -> %s\n", target3, dictionary_get(dict, target3));


    return 0;
}
