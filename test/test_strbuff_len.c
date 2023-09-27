// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_len_on_empty_buffer(void)
{
    TEST_ASSERT_EQUAL(0, strbuff_len(&buffer1));
}

static void test_strbuff_len_on_filled_buffer(void)
{
    /* Generate a random number */
    size_t len = rand_uint(TEST_MIN_STRING_LEN, TEST_BUFFER_SIZE - 1);

    /* Fill buffer1 with a string of fixed length */
    rand_string_fixed_length(buffer1.str, strbuff_capacity(&buffer1), len);

    TEST_ASSERT_EQUAL(len, strbuff_len(&buffer1));
}

static void test_strbuff_len_on_not_AZT_buffer(void)
{
    /* Fill buffer1 with a string not ending with null terminating char */
    rand_string_fixed_length(buffer1.str, strbuff_capacity(&buffer1), strbuff_capacity(&buffer1));
    *(buffer1.str + strbuff_capacity(&buffer1) - 1) = rand_char(false);

    TEST_ASSERT_EQUAL(0, strbuff_len(&buffer1));
}

void test_strbuff_len(void)
{
    RUN_TEST(test_strbuff_len_on_empty_buffer);
    RUN_TEST(test_strbuff_len_on_filled_buffer);
    RUN_TEST(test_strbuff_len_on_not_AZT_buffer);
}
