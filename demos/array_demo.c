#include <stdio.h>
#include "../src/Array.h"

int main()
{
    Array  *a = array_construct(8);
    size_t idx;

    printf("Starting capacity: %zu\n", a->capacity);

    // populate array
    for (int i=0; i<100; ++i) { array_append(a, i); }

    // display array
    array_display(a);

    // get
    idx = 65;
    printf("Getting idx %zu: %d\n", idx, array_get(a, idx));
    idx = 0;
    printf("Getting idx %zu: %d\n", idx, array_get(a, idx));
    idx = 24;
    printf("Getting idx %zu: %d\n", idx, array_get(a, idx));
    idx = 99;
    printf("Getting idx %zu: %d\n", idx, array_get(a, idx));

    printf("Ending capacity: %zu\n", a->capacity);

    array_destroy(&a);

    return 0;
}
