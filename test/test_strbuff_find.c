// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_find_sub_buffer(void)
{
    rand_string_fixed_length(buffer1.str, strbuff_capacity(&buffer1), strbuff_capacity(&buffer1) - 1);
    size_t _substring_pos = rand_uint(10, TEST_BUFFER_SIZE / 2);
    size_t _substring_len = rand_uint(TEST_MIN_STRING_LEN, TEST_BUFFER_SIZE / 2);
    memcpy(buffer2.str, (buffer1.str + _substring_pos), _substring_len);

    char *c = strbuff_find(&buffer1, &buffer2);

    TEST_ASSERT_NOT_NULL(c);
    TEST_ASSERT_EQUAL(_substring_pos, (c - buffer1.str));
    TEST_ASSERT_EQUAL_STRING_LEN(c, buffer2.str, _substring_len);
}

void test_strbuff_find(void)
{
    RUN_TEST(test_strbuff_find_sub_buffer);
}
