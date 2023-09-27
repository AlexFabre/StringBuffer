// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_end_with_same_ending(void)
{
    size_t _str_len = rand_uint(TEST_MIN_STRING_LEN, TEST_BUFFER_SIZE / 3);
    rand_string_fixed_length(buffer1.str, strbuff_capacity(&buffer1), _str_len);
    rand_string_fixed_length(buffer2.str, strbuff_capacity(&buffer2), _str_len);

    memcpy(buffer1.str + _str_len, buffer2.str, _str_len + 1);

    TEST_ASSERT_TRUE(strbuff_ends_with(&buffer1, &buffer2));
}

static void test_strbuff_end_with_different_ending(void)
{
    rand_string(buffer1.str, strbuff_capacity(&buffer1));

    size_t _str_len = rand_uint(TEST_MIN_STRING_LEN, TEST_BUFFER_SIZE / 2);
    rand_string_fixed_length(buffer2.str, strbuff_capacity(&buffer2), _str_len);

    TEST_ASSERT_FALSE(strbuff_ends_with(&buffer1, &buffer2));
}

void test_strbuff_end_with(void)
{
    RUN_TEST(test_strbuff_end_with_same_ending);
    RUN_TEST(test_strbuff_end_with_different_ending);
}
