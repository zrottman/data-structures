#include "../src/Heap.h"

int main() {

    Heap* h = heap_construct();

    int  nums_count = 15;
    int *nums;

    // insert into heap
    for (int i=0; i<nums_count; ++i) { 
        printf("Inserting %d\n", i+1);
        heap_insert(h, i+1); 
        heap_display(h);
    }

    // display heap
    printf("Displaying heap\n");
    heap_display(h);
    printf("\n");

    // poll
    int polled;

    for (int i=0; i<17; ++i) {
        if (poll(h, &polled) == 0) { printf("Polling: %d\n", polled); }
        heap_display(h);
    }

    heap_destroy(&h);

    return 0;
}
