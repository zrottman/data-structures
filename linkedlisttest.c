#include <stdio.h>
#include "node.h"
#include "linkedlist.h"

int main()
{
    /* linked list test */
    LinkedList *my_list = CreateLinkedList();

    char* keys[] = {"hi", "bye", "morning", "night", "friend", "whats up"};
    char* vals[] = {"hola", "adios", "manana", "noche", "amigo", "que pasa"};

    for (int i=0; i<6; ++i) {
        ll_append(my_list, CreateNode(keys[i], vals[i]));
    }

    printf("my_list->head->value: %s/%s\n",my_list->head->key, my_list->head->val);
    printf("my_list->tail->value: %s/%s\n", my_list->tail->key, my_list->tail->val);
    printf("my_list->len        : %zu\n", my_list->len);

    ll_display(my_list);

    printf("Search for 'bye'     : %s\n", ll_search(my_list, "bye"));
    printf("Search for 'yo'      : %s\n", ll_search(my_list, "yo"));
    printf("Search for 'whats up': %s\n", ll_search(my_list, "whats up"));
    
    printf("Deleting 'night': %d\n", ll_delete_node(my_list, "night"));
    printf("Deleting 'hi': %d\n", ll_delete_node(my_list, "hi"));

    ll_display(my_list);

    printf("Search for 'night'     : %s\n", ll_search(my_list, "night"));
    printf("my_list->len: %zu\n", my_list->len);

    DestroyLinkedList(my_list);

    return 0;
}
