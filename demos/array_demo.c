#include <stdio.h>
#include "../src/Array.h"

int main()
{
    Array *a = array_construct(8);

    for (int i=0; i<100; ++i)
        array_append(a, i);
    
    for (int i=0; i<100; ++i)
        printf("%d ", a->items[i]);
    printf("\n");

    size_t idx;
    idx = 0;
    printf("Getting idx %zu: %d\n", idx, array_get(a, idx));
    idx = 10;
    printf("Getting idx %zu: %d\n", idx, array_get(a, idx));
    idx = 12;
    printf("Getting idx %zu: %d\n", idx, array_get(a, idx));
    idx = 99;
    printf("Getting idx %zu: %d\n", idx, array_get(a, idx));

    array_destroy(&a);

    return 0;
}
