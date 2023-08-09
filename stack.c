#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"

Stack* CreateStack(void)
{
    Stack* s = malloc(sizeof(Stack));
    s->top   = NULL;
    s->len   = 0;
    
    return s;
}

size_t s_push(Stack* s, Node* n)
{
    n->next = s->top;
    s->top  = n;

    return ++s->len;
}

Node* s_pop(Stack* s)
{
    Node* tmp = s->top;
    s->top = s->top->next;
    s->len--;
    return tmp;
}


void DestroyStack(Stack* s)
{
    Node* tmp;

    while (s->top != NULL) {
        tmp = s->top;
        s->top = s->top->next;
        DestroyNode(tmp);
    }

    free(s);
}
