// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

static void test_strbuff_addb_buffer_on_empty_buffer(void)
{
    sprintf(buffer2.str, "Hello");

    TEST_ASSERT_EQUAL(5, strbuff_add(&buffer1, &buffer2));
    TEST_ASSERT_EQUAL(5, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING("Hello", buffer1.str);
}

static void test_strbuff_addb_buffer_on_filled_buffer(void)
{
    sprintf(buffer1.str, "Hello");
    sprintf(buffer2.str, " world!");

    TEST_ASSERT_EQUAL(7, strbuff_add(&buffer1, &buffer2));
    TEST_ASSERT_EQUAL(12, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING("Hello world!", buffer1.str);
}

static void test_strbuff_addb_oversized_buffer(void)
{
    sprintf(buffer1.str, "Hello");
    memset(buffer2.str, 'R', strbuff_capacity(&buffer2));
    *(buffer2.str + strbuff_capacity(&buffer2) - 1) = 0;

    TEST_ASSERT_EQUAL((strbuff_capacity(&buffer2) - 1 - 5), strbuff_add(&buffer1, &buffer2));
    TEST_ASSERT_EQUAL((strbuff_capacity(&buffer1) - 1), strbuff_len(&buffer1));

    memcpy(buffer2.str, buffer1.str, strbuff_capacity(&buffer1));

    TEST_ASSERT_EQUAL_STRING(buffer2.str, buffer1.str);
}

static void test_strbuff_addb_empty_buffer(void)
{
    sprintf(buffer1.str, "Hello");

    TEST_ASSERT_EQUAL(0, strbuff_add(&buffer1, &buffer2));
    TEST_ASSERT_EQUAL(5, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL_STRING("Hello", buffer1.str);
}

void test_strbuff_addb(void)
{
    RUN_TEST(test_strbuff_addb_buffer_on_empty_buffer);
    RUN_TEST(test_strbuff_addb_buffer_on_filled_buffer);
    RUN_TEST(test_strbuff_addb_oversized_buffer);
    RUN_TEST(test_strbuff_addb_empty_buffer);
}
