#include "../src/Heap.h"

int main() {
    Heap* h;
    int five_nums[5] = {5, 2, 7, 6, 1};
    int ten_nums[10] = {5, 2, 7, 6, 1, 50, 20, 10, 12, 33};
    int fifteen_nums[15] = {5, 2, 7, 6, 1, 50, 20, 10, 12, 33, 3, 43, 51, 53, 68};
    int nums[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    /* fewer items than cap */
    h = heap_init(10, MIN);
    for (int i=0; i<5; ++i) { heap_insert(h, five_nums[i]); }
    heap_display(h);
    heap_destroy(&h);

    /* same number items as cap */
    h = heap_init(10, MIN);
    for (int i=0; i<10; ++i) { heap_insert(h, ten_nums[i]); }
    heap_display(h);
    heap_destroy(&h);

    /* more items than cap: not currently working */
    h = heap_init(10, MIN);
    for (int i=0; i<15; ++i) { heap_insert(h, fifteen_nums[i]); }
    heap_display(h);
    heap_destroy(&h);

    /* poll */
    h = heap_init(15, MIN);
    int polled;
    printf("INSERTING\n");
    for (int i=0; i<15; ++i) { 
        heap_insert(h, nums[i]); 
        heap_display(h);
    }
    poll(h, &polled);
    printf("Polling: %d\n", polled);

    for (int i=0; i<15; ++i) {
        heap_display(h);
        if (poll(h, &polled) == 0) {
            printf("Polling: %d\n", polled);
        } else {
            printf("error");
            break;
        }
    }
    heap_display(h);
    heap_destroy(&h);

    return 0;
}
