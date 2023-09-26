#include <stdio.h>
#include "array.h"

int main()
{
    Array a;

    array_init(&a, 8);

    for (int i=0; i<100; ++i)
        array_append(&a, i);
    
    for (int i=0; i<100; ++i)
        printf("%d ", a.items[i]);
    printf("\n");

    return 0;
}
