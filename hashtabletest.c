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
    HashTable* ht = CreateHashTable(10);
    char *keys[] = {"hey", "sup", "morning", "goodbye", "there", "abcde", "cedba", "baedc"};
    char *vals[] = {"hola", "que pasa", "manana", "adios", "alli", "1", "2", "3"};

    for (int i=0; i<8; ++i)
    {
        printf("`%s` hashed to %d\n", keys[i], ht_insert(ht, keys[i], vals[i]));
    }

    ht_display(ht);

    char* target = "goodbye";
    printf("%s -> %s\n", target, ht_get(ht, target));
    char* target2 = "baedc";
    printf("%s -> %s\n", target2, ht_get(ht, target2));
    char* target3 = "sdfasdfa";
    printf("%s -> %s\n", target3, ht_get(ht, target3));


    return 0;
}
