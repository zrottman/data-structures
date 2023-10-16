#include "../unity/unity.h"
#include "../src/Sort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_sort(void)
{
    int    nums[]     = { 2, 8, 3, 0, 9, 1, 4 };
    int    solution[] = { 0, 1, 2, 3, 4, 8, 9 };
    size_t len        = 7;

    merge_sort(nums, len);

    for (int i=0; i<len; ++i) {
        TEST_ASSERT_EQUAL(solution[i], nums[i]);
    }
}

void test_sort_with_dupes(void)
{
    int    nums[]     = { 2, 8, 3, 0, 9, 1, 4, 0, 8, 8, 15, 9 };
    int    solution[] = { 0, 0, 1, 2, 3, 4, 8, 8, 8, 9, 9, 15 };
    size_t len        = 12;

    merge_sort(nums, len);

    for (int i=0; i<len; ++i) {
        TEST_ASSERT_EQUAL(solution[i], nums[i]);
    }
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_sort);
    RUN_TEST(test_sort_with_dupes);
    return UNITY_END();
}
