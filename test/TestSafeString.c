#include "../src/SafeString.h"
#include "../unity/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_string_create(void) {
    struct string_t* mystr = string_create(10);
    TEST_ASSERT_EQUAL(10, mystr->cap);
    TEST_ASSERT_EQUAL_STRING("", mystr->buf);
    TEST_ASSERT_EQUAL(0, mystr->len);
    string_destroy(&mystr);
}

void test_string_create_with_0_length(void) {
    struct string_t* mystr = string_create(0);
    TEST_ASSERT_EQUAL(0, mystr->cap);
    TEST_ASSERT_EQUAL_STRING("", mystr->buf);
    TEST_ASSERT_EQUAL(0, mystr->len);
    string_destroy(&mystr);
}

void test_string_set_for_strings_less_than_cap(void) {
    struct string_t* mystr = string_create(10);

    TEST_ASSERT_EQUAL(0, string_set(mystr, "hello"));
    TEST_ASSERT_EQUAL(5, mystr->len);
    TEST_ASSERT_EQUAL_STRING("hello", mystr->buf);

    TEST_ASSERT_EQUAL(0, string_set(mystr, "hola"));
    TEST_ASSERT_EQUAL(4, mystr->len);
    TEST_ASSERT_EQUAL_STRING("hola", mystr->buf);

    TEST_ASSERT_EQUAL(0, string_set(mystr, ""));
    TEST_ASSERT_EQUAL(0, mystr->len);
    TEST_ASSERT_EQUAL_STRING("", mystr->buf);

    TEST_ASSERT_EQUAL(0, string_set(mystr, "howdeedo"));
    TEST_ASSERT_EQUAL(8, mystr->len);
    TEST_ASSERT_EQUAL_STRING("howdeedo", mystr->buf);

    string_destroy(&mystr);
}

void test_string_set_for_strings_equal_to_cap(void) {
    struct string_t* mystr = string_create(10);

    TEST_ASSERT_EQUAL(0, string_set(mystr, "abcdefghi"));
    TEST_ASSERT_EQUAL(9, mystr->len);
    TEST_ASSERT_EQUAL_STRING("abcdefghi", mystr->buf);

    string_destroy(&mystr);
}

void test_string_set_for_strings_greater_than_cap(void) {
    struct string_t* mystr = string_create(10);

    // invalid
    TEST_ASSERT_EQUAL(1, string_set(mystr, "abcdefghij"));
    TEST_ASSERT_EQUAL(0, mystr->len);
    TEST_ASSERT_EQUAL_STRING("", mystr->buf);

    // valid
    TEST_ASSERT_EQUAL(0, string_set(mystr, "abcdefghi"));
    TEST_ASSERT_EQUAL(9, mystr->len);
    TEST_ASSERT_EQUAL_STRING("abcdefghi", mystr->buf);

    // invalid
    TEST_ASSERT_EQUAL(1, string_set(mystr, "abcdefghij"));
    TEST_ASSERT_EQUAL(9, mystr->len);
    TEST_ASSERT_EQUAL_STRING("abcdefghi", mystr->buf);

    string_destroy(&mystr);
}


void test_string_append_in_valid_cases(void) {
    struct string_t* mystr = string_create(10);

    TEST_ASSERT_EQUAL(0, string_appendc(mystr, 'a'));
    TEST_ASSERT_EQUAL(1, mystr->len);
    TEST_ASSERT_EQUAL_STRING("a", mystr->buf);

    TEST_ASSERT_EQUAL(0, string_appendc(mystr, 'b'));
    TEST_ASSERT_EQUAL(2, mystr->len);
    TEST_ASSERT_EQUAL_STRING("ab", mystr->buf);

    TEST_ASSERT_EQUAL(0, string_appendc(mystr, 'c'));
    TEST_ASSERT_EQUAL(3, mystr->len);
    TEST_ASSERT_EQUAL_STRING("abc", mystr->buf);

    TEST_ASSERT_EQUAL(0, string_set(mystr, "xyz"));
    TEST_ASSERT_EQUAL(3, mystr->len);
    TEST_ASSERT_EQUAL_STRING("xyz", mystr->buf);
    TEST_ASSERT_EQUAL(0, string_appendc(mystr, 'a'));
    TEST_ASSERT_EQUAL(4, mystr->len);
    TEST_ASSERT_EQUAL_STRING("xyza", mystr->buf);

    string_destroy(&mystr);
}

void test_string_append_in_invalid_cases(void) {
    struct string_t* mystr = string_create(3);

    TEST_ASSERT_EQUAL(0, string_appendc(mystr, 'a'));
    TEST_ASSERT_EQUAL(1, mystr->len);
    TEST_ASSERT_EQUAL_STRING("a", mystr->buf);

    TEST_ASSERT_EQUAL(0, string_appendc(mystr, 'b'));
    TEST_ASSERT_EQUAL(2, mystr->len);
    TEST_ASSERT_EQUAL_STRING("ab", mystr->buf);

    TEST_ASSERT_EQUAL(1, string_appendc(mystr, 'c'));
    TEST_ASSERT_EQUAL(2, mystr->len);
    TEST_ASSERT_EQUAL_STRING("ab", mystr->buf);

    string_destroy(&mystr);
}

void test_string_reset(void) {
    struct string_t* mystr = string_create(10);

    string_set(mystr, "hello");
    string_set(mystr, "");
    string_appendc(mystr, '1');

    TEST_ASSERT_EQUAL_STRING("1", mystr->buf);

    string_destroy(&mystr);
}


int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_string_create);
    RUN_TEST(test_string_create_with_0_length);
    RUN_TEST(test_string_set_for_strings_less_than_cap);
    RUN_TEST(test_string_set_for_strings_equal_to_cap);
    RUN_TEST(test_string_set_for_strings_greater_than_cap);
    RUN_TEST(test_string_append_in_valid_cases);
    RUN_TEST(test_string_append_in_invalid_cases);
    RUN_TEST(test_string_reset);

    return UNITY_END();
}
