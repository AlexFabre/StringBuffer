// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_prints_on_empty_buffer(void)
{
    char _rand_str[strbuff_capacity(&buffer1)];
    rand_string(_rand_str, strbuff_capacity(&buffer1));
    size_t _len = strlen(_rand_str);

    TEST_ASSERT_EQUAL(_len, strbuff_print(&buffer1, _rand_str));
    TEST_ASSERT_EQUAL(_len, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING(_rand_str, buffer1.str);
}

static void test_strbuff_prints_on_filled_buffer(void)
{
    rand_string(buffer1.str, strbuff_capacity(&buffer1));

    char _rand_str[strbuff_capacity(&buffer1)];
    rand_string(_rand_str, strbuff_capacity(&buffer1));
    size_t _len = strlen(_rand_str);

    TEST_ASSERT_EQUAL(_len, strbuff_print(&buffer1, _rand_str));
    TEST_ASSERT_EQUAL(_len, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING_LEN(_rand_str, buffer1.str, _len);
}

static void test_strbuff_prints_empty_str(void)
{
    /* Fill buffer1 with a random string */
    rand_string(buffer1.str, strbuff_capacity(&buffer1));

    TEST_ASSERT_EQUAL(0, strbuff_print(&buffer1, ""));
    TEST_ASSERT_EQUAL(0, strbuff_len(&buffer1));
}

void test_strbuff_prints(void)
{
    RUN_TEST(test_strbuff_prints_on_empty_buffer);
    RUN_TEST(test_strbuff_prints_on_filled_buffer);
    RUN_TEST(test_strbuff_prints_empty_str);
}
