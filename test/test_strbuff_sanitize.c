// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_sanitize_filled_buffer(void)
{
    /* Fill buffer1 with random string ending with null terminating char */
    rand_string(buffer1.str, strbuff_capacity(&buffer1));

    /* Get the size of the random string */
    size_t _len = strbuff_len(&buffer1);

    /* Place a null terminating char somewhere */
    size_t pos       = rand_uint(TEST_MIN_STRING_LEN - 1, _len);
    buffer1.str[pos] = 0;

    /* Copy buffer1 to buffer2 up to this null terminating char*/
    memcpy(buffer2.str, buffer1.str, pos + 1);

    TEST_ASSERT_EQUAL(strbuff_capacity(&buffer1) - pos, strbuff_sanitize(&buffer1));
    TEST_ASSERT_EQUAL(pos, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL(memcmp(buffer1.str, buffer2.str, strbuff_capacity(&buffer1)), 0);
}

static void test_strbuff_sanitize_full_buffer(void)
{
    /* Fill buffer1 with random string not ending with null temrinating char (dummy byte array) */
    rand_string_fixed_length(buffer1.str, strbuff_capacity(&buffer1), strbuff_capacity(&buffer1));
    *(buffer1.str + strbuff_capacity(&buffer1) - 1) = rand_char(false);

    TEST_ASSERT_EQUAL(strbuff_capacity(&buffer1), strbuff_sanitize(&buffer1));
    TEST_ASSERT_EQUAL(0, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL(memcmp(buffer1.str, buffer2.str, strbuff_capacity(&buffer1)), 0);
}

void test_strbuff_sanitize(void)
{
    RUN_TEST(test_strbuff_sanitize_filled_buffer);
    RUN_TEST(test_strbuff_sanitize_full_buffer);
}
