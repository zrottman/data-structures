#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

typedef struct Stack {
    Node*  top;
    size_t len;
} Stack;

Stack* CreateStack(void);
void   DestroyStack(Stack* s);
Node*  s_pop(Stack *s);
size_t s_push(Stack *s, Node *n);

#endif // STACK_H
