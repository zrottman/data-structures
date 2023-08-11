#include <stdio.h>
#include "node.h"
#include "stack.h"

int main()
{
    Stack* s = CreateStack();

    char *keys[] = {"hi", "bye", "here", "there", "night"};
    char *values[] = {"hola", "adios", "aqui", "alli", "noche"};

    for (int i=0; i<5; ++i)
        s_push(s, CreateNode(keys[i], values[i], STRING));


    printf("Stack length: %zu\n", s->len);

    Node* popped;

    popped = s_pop(s);
    printf("Popped: "); 
    node_print(popped);
    printf("\n");
    printf("Stack length: %zu\n", s->len);
    DestroyNode(popped);

    popped = s_pop(s);
    printf("Popped: "); 
    node_print(popped);
    printf("\n");
    printf("Stack length: %zu\n", s->len);
    DestroyNode(popped);
    
    popped = s_pop(s);
    printf("Popped: "); 
    node_print(popped);
    printf("\n");
    printf("Stack length: %zu\n", s->len);
    DestroyNode(popped);

    DestroyStack(s);

    return 0;
}
