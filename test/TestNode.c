#include "../unity/unity.h"
#include "../src/Node.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_CreateNode_handles_string_vals(void)
{
    Node *node = CreateNode("myKey", "myVal", STRING);
    TEST_ASSERT_EQUAL_STRING(node->val.data.s, "myVal");
    DestroyNode(node);
}

void test_CreateNode_handles_float_vals(void)
{
    Node *node = CreateNode("myKey", &(float){3.1415}, FLOAT);
    TEST_ASSERT_EQUAL(node->val.data.f, 3.1415);
    DestroyNode(node);
}

void test_CreateNode_handles_int_vals(void)
{
    Node *node = CreateNode("myKey", &(int){1234}, INT);
    TEST_ASSERT_EQUAL(node->val.data.i, 1234);
    DestroyNode(node);
}

void test_node_update(void)
{
    Node *node = CreateNode("myKey", "string value", STRING);
    node_update(node, "new string value", STRING);
    TEST_ASSERT_EQUAL_STRING(node->val.data.s, "new string value");
    node_update(node, &(int){12345}, INT);
    TEST_ASSERT_EQUAL(node->val.data.i, 12345);
    node_update(node, &(float){1.2345}, FLOAT);
    TEST_ASSERT_EQUAL(node->val.data.f, 1.2345);
    node_update(node, "it's a string once more", STRING);
    TEST_ASSERT_EQUAL_STRING(node->val.data.s, "it's a string once more");
    node_update(node, "it's another string", STRING);
    TEST_ASSERT_EQUAL_STRING(node->val.data.s, "it's another string");
    DestroyNode(node);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_CreateNode_handles_string_vals);
    RUN_TEST(test_CreateNode_handles_float_vals);
    RUN_TEST(test_CreateNode_handles_int_vals);
    RUN_TEST(test_node_update);
    return UNITY_END();
}
