#include "../unity/unity.h"
#include "../src/LinkedList.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void passing_test(void)
{
    TEST_ASSERT_TRUE(1 == 1);
}

void failing_test(void)
{
    TEST_ASSERT_TRUE(2 == 1);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(passing_test);
    RUN_TEST(failing_test);
    return UNITY_END();
}
