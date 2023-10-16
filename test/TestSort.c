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

    merge_sort(&nums, len);

    for (int i=0; i<len; ++i) {
        TEST_ASSSERT_EQUAL(solution[i], nums[i]);
    }
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_CreateNode_handles_string_vals);
    RUN_TEST(test_CreateNode_handles_float_vals);
    RUN_TEST(test_CreateNode_handles_int_vals);
    RUN_TEST(failing_test);
    RUN_TEST(test_node_update);
    return UNITY_END();
}
