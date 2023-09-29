#include "../src/Heap.h"

int main() {
    Heap* h;
    int five_nums[5] = {5, 2, 7, 6, 1};
    int ten_nums[10] = {5, 2, 7, 6, 1, 50, 20, 10, 12, 33};
    int fifteen_nums[15] = {5, 2, 7, 6, 1, 50, 20, 10, 12, 33, 3, 43, 51, 53, 68};

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
    h = heap_init(10, MIN);
    for (int i=0; i<10; ++i) { heap_insert(h, ten_nums[i]); }
    heap_display(h);
    printf("Polling: %d\n", poll(h));
    heap_display(h);
    printf("Polling: %d\n", poll(h));
    heap_display(h);
    printf("Polling: %d\n", poll(h));
    heap_display(h);
    printf("Polling: %d\n", poll(h));
    heap_display(h);
    printf("Polling: %d\n", poll(h));
    heap_display(h);
    heap_destroy(&h);

    return 0;
}
