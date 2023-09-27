// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_addf_on_empty_buffer(void)
{
    char _rand_str[strbuff_capacity(&buffer1)];
    rand_string(_rand_str, strbuff_capacity(&buffer1));
    size_t _len = strlen(_rand_str);

    TEST_ASSERT_EQUAL(_len, strbuff_addf(&buffer1, "%s", _rand_str));
    TEST_ASSERT_EQUAL(_len, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING(_rand_str, buffer1.str);
}

static void test_strbuff_addf_on_filled_buffer(void)
{
    /* Generate a size for the buffers so that we can add two of them without reaching the maximum capacity of buffer1 */
    const size_t str_size = (strbuff_capacity(&buffer1) / 3);

    char _rand_str1[str_size + 1];
    rand_string_fixed_length(_rand_str1, sizeof(_rand_str1), str_size);
    strcpy(buffer1.str, _rand_str1);

    char _rand_str2[str_size + 1];
    rand_string_fixed_length(_rand_str2, sizeof(_rand_str2), str_size);

    TEST_ASSERT_EQUAL(str_size, strbuff_addf(&buffer1, "%s", _rand_str2));
    TEST_ASSERT_EQUAL((2 * str_size), strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING_LEN(_rand_str1, buffer1.str, str_size);
    TEST_ASSERT_EQUAL_STRING_LEN(_rand_str2, buffer1.str + str_size, str_size);
}

static void test_strbuff_addf_on_almost_full_buffer(void)
{
    /* Number of free char space at the end of buffer1 */
    size_t free_space = rand_uint(1, TEST_MIN_STRING_LEN / 2);

    /* Fill buffer1 with a string with the corresponding free spaces at the end */
    char _rand_str1[strbuff_capacity(&buffer1)];
    rand_string_fixed_length(_rand_str1, sizeof(_rand_str1), strbuff_capacity(&buffer1) - free_space - 1);
    strcpy(buffer1.str, _rand_str1);

    /* Generate a string bigger than the number of char that can fill in buffer1 */
    rand_string_fixed_length(buffer2.str, strbuff_capacity(&buffer2), free_space + 1);

    TEST_ASSERT_EQUAL(free_space, strbuff_addf(&buffer1, "%s", buffer2.str));
    TEST_ASSERT_EQUAL(strbuff_capacity(&buffer1) - 1, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING_LEN(buffer2.str, buffer1.str + strbuff_capacity(&buffer1) - free_space - 1, free_space);
}

static void test_strbuff_addf_empty_str(void)
{
    /* Fill buffer1 with a random string */
    char _rand_str[strbuff_capacity(&buffer1)];
    rand_string(_rand_str, strbuff_capacity(&buffer1));
    size_t _len = strlen(_rand_str);
    strcpy(buffer1.str, _rand_str);

    TEST_ASSERT_EQUAL(0, strbuff_addf(&buffer1, "%s", ""));
    TEST_ASSERT_EQUAL(_len, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING(_rand_str, buffer1.str);
}

void test_strbuff_addf(void)
{
    RUN_TEST(test_strbuff_addf_on_empty_buffer);
    RUN_TEST(test_strbuff_addf_on_filled_buffer);
    RUN_TEST(test_strbuff_addf_on_almost_full_buffer);
    RUN_TEST(test_strbuff_addf_empty_str);
}
