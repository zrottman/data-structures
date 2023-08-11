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
        ll_append(my_list, keys[i], vals[i], STRING);
    }

    int myint = 124123;
    float myfloat = 123.1242;
    ll_append(my_list, "my int", &myint, INT);
    ll_append(my_list, "my float", &myfloat, FLOAT);

    ll_display(my_list);

    printf("Search for 'bye'     : %d\n", ll_search(my_list, "bye"));
    printf("Search for 'yo'      : %d\n", ll_search(my_list, "yo"));
    printf("Search for 'whats up': %d\n", ll_search(my_list, "whats up"));
    
    printf("Deleting 'night'     : %d\n", ll_delete_node(my_list, "night"));
    printf("Deleting 'hi'        : %d\n", ll_delete_node(my_list, "hi"));
    printf("Deleting 'addflkasd' : %d\n", ll_delete_node(my_list, "addflkasd"));

    ll_display(my_list);

    printf("Search for 'night'   : %d\n", ll_search(my_list, "night"));
    printf("my_list->len         : %zu\n", my_list->len);

    DestroyLinkedList(my_list);

    return 0;
}
