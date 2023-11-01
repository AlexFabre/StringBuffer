// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_prefixs_buffer_on_non_empty_buffer(void)
{
    rand_string(buffer1.str, strbuff_capacity(&buffer1) / 3);

    char tmp_buffer[TEST_BUFFER_SIZE];
    memcpy(tmp_buffer, buffer1.str, strbuff_capacity(&buffer1));

    char tmp_buffer2[TEST_BUFFER_SIZE / 3];

    rand_string(tmp_buffer2, sizeof(tmp_buffer2));

    size_t n1 = strlen(buffer1.str);
    size_t n2 = strlen(tmp_buffer2);

    TEST_ASSERT_EQUAL(n2, strbuff_prefix(&buffer1, tmp_buffer2));
    TEST_ASSERT_EQUAL((n1 + n2), strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING_LEN(tmp_buffer2, buffer1.str, n2);
    TEST_ASSERT_EQUAL_STRING_LEN(tmp_buffer, buffer1.str + n2, n1);
}

static void test_strbuff_prefixs_buffer_on_filled_buffer(void)
{
    rand_string_fixed_length(buffer1.str, strbuff_capacity(&buffer1), strbuff_capacity(&buffer1) - 1);

    char tmp_buffer2[] = "Hello";

    TEST_ASSERT_EQUAL(5, strbuff_prefix(&buffer1, tmp_buffer2));
    TEST_ASSERT_EQUAL(strbuff_capacity(&buffer1) - 1, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING_LEN("Hello", buffer1.str, 5);
}

void test_strbuff_prefixs(void)
{
    RUN_TEST(test_strbuff_prefixs_buffer_on_non_empty_buffer);
    RUN_TEST(test_strbuff_prefixs_buffer_on_filled_buffer);
}
