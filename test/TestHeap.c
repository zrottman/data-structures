#include "../src/Heap.h"
#include "../unity/unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_create_heap(void) {
    Heap* h = NULL;
    h = heap_init(10, MAX);
    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL(h->length, 0);
    TEST_ASSERT_EQUAL(h->capacity, 10);
    heap_destroy(&h);
    TEST_ASSERT_NULL(h);
}

void test_heap_swap(void) {
    Heap* h = heap_init(10, MAX);
    for (int i=0; i<10; ++i) {
        h->items[i] = i+1;
    }
    heap_swap(h, 2, 5);
    TEST_ASSERT_EQUAL(h->items[2], 6);
    TEST_ASSERT_EQUAL(h->items[5], 3);
    heap_swap(h, 2, 5);
    TEST_ASSERT_EQUAL(h->items[2], 3);
    TEST_ASSERT_EQUAL(h->items[5], 6);
    heap_destroy(&h);
}

void test_get_parent_idx(void) {
    TEST_ASSERT_EQUAL(get_parent_idx(1), 0);
    TEST_ASSERT_EQUAL(get_parent_idx(2), 0);
    TEST_ASSERT_EQUAL(get_parent_idx(3), 1);
    TEST_ASSERT_EQUAL(get_parent_idx(4), 1);
    TEST_ASSERT_EQUAL(get_parent_idx(5), 2);
    TEST_ASSERT_EQUAL(get_parent_idx(6), 2);
    TEST_ASSERT_EQUAL(get_parent_idx(7), 3);
    TEST_ASSERT_EQUAL(get_parent_idx(8), 3);
    TEST_ASSERT_EQUAL(get_parent_idx(9), 4);
    TEST_ASSERT_EQUAL(get_parent_idx(10), 4);
    TEST_ASSERT_EQUAL(get_parent_idx(11), 5);
    TEST_ASSERT_EQUAL(get_parent_idx(12), 5);
    TEST_ASSERT_EQUAL(get_parent_idx(13), 6);
    TEST_ASSERT_EQUAL(get_parent_idx(14), 6);
}

void test_get_left_child_idx(void) {
    TEST_ASSERT_EQUAL(get_left_child_idx(0), 1);
    TEST_ASSERT_EQUAL(get_left_child_idx(1), 3);
    TEST_ASSERT_EQUAL(get_left_child_idx(2), 5);
    TEST_ASSERT_EQUAL(get_left_child_idx(3), 7);
    TEST_ASSERT_EQUAL(get_left_child_idx(4), 9);
    TEST_ASSERT_EQUAL(get_left_child_idx(5), 11);
    TEST_ASSERT_EQUAL(get_left_child_idx(6), 13);
    TEST_ASSERT_EQUAL(get_left_child_idx(7), 15);
}

void test_get_right_child_idx(void) {
    TEST_ASSERT_EQUAL(get_right_child_idx(0), 2);
    TEST_ASSERT_EQUAL(get_right_child_idx(1), 4);
    TEST_ASSERT_EQUAL(get_right_child_idx(2), 6);
    TEST_ASSERT_EQUAL(get_right_child_idx(3), 8);
    TEST_ASSERT_EQUAL(get_right_child_idx(4), 10);
    TEST_ASSERT_EQUAL(get_right_child_idx(5), 12);
    TEST_ASSERT_EQUAL(get_right_child_idx(6), 14);
    TEST_ASSERT_EQUAL(get_right_child_idx(7), 16);
}

void test_get_parent(void) {
    Heap* h = heap_init(15, MAX);
    for (int i=0; i<15; ++i) {
        h->items[i] = i*10;
    }
    TEST_ASSERT_EQUAL(get_parent(h, 1), 0);
    TEST_ASSERT_EQUAL(get_parent(h, 2), 0);
    TEST_ASSERT_EQUAL(get_parent(h, 3), 10);
    TEST_ASSERT_EQUAL(get_parent(h, 4), 10);
    TEST_ASSERT_EQUAL(get_parent(h, 5), 20);
    TEST_ASSERT_EQUAL(get_parent(h, 6), 20);
    TEST_ASSERT_EQUAL(get_parent(h, 7), 30);
    TEST_ASSERT_EQUAL(get_parent(h, 8), 30);
    TEST_ASSERT_EQUAL(get_parent(h, 9), 40);
    TEST_ASSERT_EQUAL(get_parent(h, 10), 40);
    TEST_ASSERT_EQUAL(get_parent(h, 11), 50);
    TEST_ASSERT_EQUAL(get_parent(h, 12), 50);
    TEST_ASSERT_EQUAL(get_parent(h, 13), 60);
    TEST_ASSERT_EQUAL(get_parent(h, 14), 60);
    heap_destroy(&h);
}

void test_get_left_child(void) {
    Heap* h = heap_init(15, MAX);
    for (int i=0; i<15; ++i) {
        h->items[i] = i*10;
    }
    TEST_ASSERT_EQUAL(get_left_child(h, 0), 10);
    TEST_ASSERT_EQUAL(get_left_child(h, 1), 30);
    TEST_ASSERT_EQUAL(get_left_child(h, 2), 50);
    TEST_ASSERT_EQUAL(get_left_child(h, 3), 70);
    TEST_ASSERT_EQUAL(get_left_child(h, 4), 90);
    TEST_ASSERT_EQUAL(get_left_child(h, 5), 110);
    TEST_ASSERT_EQUAL(get_left_child(h, 6), 130);
    heap_destroy(&h);
}

void test_get_right_child(void) {
    Heap* h = heap_init(15, MAX);
    for (int i=0; i<15; ++i) {
        h->items[i] = i*10;
    }
    TEST_ASSERT_EQUAL(get_right_child(h, 0), 20);
    TEST_ASSERT_EQUAL(get_right_child(h, 1), 40);
    TEST_ASSERT_EQUAL(get_right_child(h, 2), 60);
    TEST_ASSERT_EQUAL(get_right_child(h, 3), 80);
    TEST_ASSERT_EQUAL(get_right_child(h, 4), 100);
    TEST_ASSERT_EQUAL(get_right_child(h, 5), 120);
    TEST_ASSERT_EQUAL(get_right_child(h, 6), 140);
    heap_destroy(&h);
}

void test_has_parent(void) {
    Heap* h = heap_init(15, MAX);
    for (int i=0; i<15; ++i) { 
        h->items[i] = i*10; 
        h->length++;
    }

    TEST_ASSERT_FALSE(has_parent(h, 0));
    TEST_ASSERT_TRUE(has_parent(h, 1));
    TEST_ASSERT_TRUE(has_parent(h, 10));
    TEST_ASSERT_FALSE(has_parent(h, 100));

    heap_destroy(&h);
}

void test_has_left_child(void) {
    Heap* h = heap_init(15, MAX);
    for (int i=0; i<15; ++i) { 
        h->items[i] = i*10; 
        h->length++;
    }

    TEST_ASSERT_TRUE(has_left_child(h, 0));
    TEST_ASSERT_TRUE(has_left_child(h, 6));
    TEST_ASSERT_FALSE(has_left_child(h, 7));
    TEST_ASSERT_FALSE(has_left_child(h, 70));

    heap_destroy(&h);
}

void test_has_right_child(void) {
    Heap* h = heap_init(15, MAX);
    for (int i=0; i<15; ++i) { 
        h->items[i] = i*10; 
        h->length++;
    }

    TEST_ASSERT_TRUE(has_right_child(h, 0));
    TEST_ASSERT_TRUE(has_right_child(h, 6));
    TEST_ASSERT_FALSE(has_right_child(h, 8));
    TEST_ASSERT_FALSE(has_right_child(h, 40));

    heap_destroy(&h);
}

// test for polling from empty heap

void test_poll(void) {
    Heap* h = heap_init(15, MAX);
    int polled;
    int success;
    int nums[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    for (int i=0; i<15; ++i) { heap_insert(h, nums[i]); }
    for (int i=0; i<15; ++i) {
        success = poll(h, &polled);
        TEST_ASSERT_EQUAL(15-i, polled);
        TEST_ASSERT_EQUAL(success, SUCCESS);
    }
    success = poll(h, &polled);
    TEST_ASSERT_EQUAL(EMPTY_HEAP_SENTINEL, polled);
    TEST_ASSERT_EQUAL(HEAP_EMPTY_ERROR, success);
    heap_destroy(&h);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_create_heap);
    RUN_TEST(test_heap_swap);
    RUN_TEST(test_get_parent_idx);
    RUN_TEST(test_get_left_child_idx);
    RUN_TEST(test_get_right_child_idx);
    RUN_TEST(test_get_parent);
    RUN_TEST(test_get_left_child);
    RUN_TEST(test_get_right_child);
    RUN_TEST(test_has_parent);
    RUN_TEST(test_has_left_child);
    RUN_TEST(test_has_right_child);
    RUN_TEST(test_poll);
    return UNITY_END();
}
