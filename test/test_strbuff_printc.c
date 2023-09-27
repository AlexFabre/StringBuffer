// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_printc_on_empty_buffer(void)
{
    TEST_ASSERT_EQUAL(1, strbuff_print(&buffer1, 'A'));
    TEST_ASSERT_EQUAL(1, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING("A", buffer1.str);
}

static void test_strbuff_printc_on_filled_buffer(void)
{
    sprintf(buffer1.str, "Hello");

    TEST_ASSERT_EQUAL(1, strbuff_print(&buffer1, '!'));
    TEST_ASSERT_EQUAL(1, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING("!", buffer1.str);
}

static void test_strbuff_printc_on_full_buffer(void)
{
    memset(buffer1.str, 'R', strbuff_capacity(&buffer1));
    *(buffer1.str + strbuff_capacity(&buffer1) - 1) = 0;
    memcpy(buffer2.str, buffer1.str, strbuff_capacity(&buffer1));

    TEST_ASSERT_EQUAL(1, strbuff_print(&buffer1, 'T'));
    TEST_ASSERT_EQUAL(1, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING("T", buffer1.str);
}

static void test_strbuff_printc_empty_char(void)
{
    sprintf(buffer1.str, "Hello");
    sprintf(buffer2.str, "Hello");

    TEST_ASSERT_EQUAL(1, strbuff_print(&buffer1, '\0'));
    TEST_ASSERT_EQUAL(0, strbuff_len(&buffer1));
}

void test_strbuff_printc(void)
{
    RUN_TEST(test_strbuff_printc_on_empty_buffer);
    RUN_TEST(test_strbuff_printc_on_filled_buffer);
    RUN_TEST(test_strbuff_printc_on_full_buffer);
    RUN_TEST(test_strbuff_printc_empty_char);
}
