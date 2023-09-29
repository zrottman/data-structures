#include "../src/Heap.h"

int main() {

    Heap* h = heap_construct();

    int  nums_count = 15;
    int  *nums;
    int  insert;
    int  polled;

    // insert into heap
    printf("Inserting into heap: ");
    for (int i=0; i<nums_count; ++i) { 
        insert = i+1;
        printf("%d ", insert);
        heap_insert(h, insert); 
    }
    printf("\n");

    // display heap
    printf("Displaying underlying array: ");
    heap_display(h);

    // poll
    printf("Polling from heap: ");
    for (int i=0; i<17; ++i) {
        if (poll(h, &polled) == 0) {
            printf("%d ", polled); 
        }
    }
    printf("\n");

    heap_destroy(&h);

    return 0;
}
