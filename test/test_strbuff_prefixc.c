// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_prefixc_buffer_on_non_empty_buffer(void)
{
    rand_string(buffer1.str, strbuff_capacity(&buffer1) / 3);

    char tmp_buffer[TEST_BUFFER_SIZE];
    memcpy(tmp_buffer, buffer1.str, strbuff_capacity(&buffer1));

    char c = rand_char(false);

    size_t n1 = strlen(buffer1.str);

    TEST_ASSERT_EQUAL(1, strbuff_prefix(&buffer1, c));
    TEST_ASSERT_EQUAL((n1 + 1), strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING_LEN(&c, buffer1.str, 1);
    TEST_ASSERT_EQUAL_STRING_LEN(tmp_buffer, buffer1.str + 1, n1);
}

static void test_strbuff_prefixc_buffer_on_filled_buffer(void)
{
    rand_string_fixed_length(buffer1.str, strbuff_capacity(&buffer1), strbuff_capacity(&buffer1) - 1);

    char c = 'H';

    TEST_ASSERT_EQUAL(1, strbuff_prefix(&buffer1, c));
    TEST_ASSERT_EQUAL(strbuff_capacity(&buffer1) - 1, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING_LEN("H", buffer1.str, 1);
}

void test_strbuff_prefixc(void)
{
    RUN_TEST(test_strbuff_prefixc_buffer_on_non_empty_buffer);
    RUN_TEST(test_strbuff_prefixc_buffer_on_filled_buffer);
}
