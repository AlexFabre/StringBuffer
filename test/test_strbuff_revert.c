// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_revert_filled_buffer(void)
{
    /* Fill buffer1 with random string ending with null terminating char */
    rand_string(buffer1.str, strbuff_capacity(&buffer1));

    /* Get the size of the random string */
    size_t _len = strbuff_len(&buffer1);

    /* Copy buffer1 to buffer2 up to this null terminating char*/
    memcpy(buffer2.str, buffer1.str, _len + 1);

    TEST_ASSERT_EQUAL(_len, strbuff_revert(&buffer1));
    TEST_ASSERT_EQUAL(_len, strbuff_revert(&buffer1));
    TEST_ASSERT_EQUAL(memcmp(buffer1.str, buffer2.str, _len), 0);
}

static void test_strbuff_revert_full_buffer(void)
{
    /* Fill buffer1 with random string not ending with null temrinating char (dummy byte array) */
    rand_string_fixed_length(buffer1.str, strbuff_capacity(&buffer1), strbuff_capacity(&buffer1));
    *(buffer1.str + strbuff_capacity(&buffer1) - 1) = rand_char(false);

    TEST_ASSERT_EQUAL(0, strbuff_revert(&buffer1));
}

void test_strbuff_revert(void)
{
    RUN_TEST(test_strbuff_revert_filled_buffer);
    RUN_TEST(test_strbuff_revert_full_buffer);
}
