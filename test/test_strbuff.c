// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "test_strbuff.h"

new_strbuff(buffer1, TEST_BUFFER_SIZE, 0);
new_strbuff(buffer2, TEST_BUFFER_SIZE, 0);

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
    memset(buffer1.str, 0, buffer1.capacity);
    memset(buffer2.str, 0, buffer2.capacity);
}

/**
 * Generate a random sized string that fits in the destination buffer.
 *
 * @param dest_buffer The destination buffer where the generated string will be stored.
 * @param dest_buffer_size The size of the destination buffer.
 */
void rand_string(char dest_buffer[], size_t dest_buffer_size)
{
    size_t string_length = rand_uint(TEST_MIN_STRING_LEN, TEST_BUFFER_SIZE - 1);
    rand_string_fixed_length(dest_buffer, dest_buffer_size, string_length);
}

/**
 * Generate a fixed length string into a destination buffer.
 *
 * @param dest_buffer The destination buffer where the generated string will be stored.
 * @param dest_buffer_size The size of the destination buffer.
 * @param string_length The desired length of the generated string.
 */
void rand_string_fixed_length(char dest_buffer[], size_t dest_buffer_size, size_t string_length)
{
    if (string_length >= dest_buffer_size - 1) {
        string_length = dest_buffer_size - 1;
    }

    for (size_t n = 0; n < string_length; n++) {
        dest_buffer[n] = rand_char(false);
    }
    dest_buffer[string_length] = '\0';
}

/**
 * Generate a random character.
 *
 * @param can_be_null A boolean parameter indicating whether the result char can be null or not.
 * @return The randomly generated character.
 */
char rand_char(bool can_be_null)
{
    char c = 0;

    if (can_be_null) {
        c = (char)(rand() % 128);
        return c;
    } else {
        while (!c) {
            c = (char)(rand() % 128);
        }
        return c;
    }
}

/**
 * Generates a random positive integer between the given minimum and maximum bounds.
 *
 * @param min The minimum bound for the generated random number.
 * @param max The maximum bound for the generated random number.
 *
 * @return The randomly generated positive integer.
 */
unsigned long rand_uint(unsigned long min, unsigned long max)
{
    assert(min < max);

    unsigned long u = min + (((unsigned long)rand()) % (max - min));
    return u;
}

static void test_strbuff_capacity(void)
{
    TEST_ASSERT_EQUAL(TEST_BUFFER_SIZE, strbuff_capacity(&buffer1));
}

static void test_strbuff_clear(void)
{
    do {
        rand_string(buffer1.str, strbuff_capacity(&buffer1));
    } while (strbuff_len(&buffer1) == 0);

    strbuff_clear(&buffer1);

    TEST_ASSERT_EQUAL(0, strbuff_len(&buffer1));
    TEST_ASSERT_EQUAL(memcmp(buffer1.str, buffer2.str, strbuff_capacity(&buffer1)), 0);
}

int main(void)
{
    assert(buffer1.capacity == buffer2.capacity);

    clock_t begin, end;
    double  time_spent;

    begin = clock();

    srand((unsigned int)time(NULL)); // Initialization, should only be called once.
    UNITY_BEGIN();
    for (size_t i = 0; i < UNIT_TEST_LOOP; i++) {
        RUN_TEST(test_strbuff_capacity);
        RUN_TEST(test_strbuff_clear);
        test_strbuff_addb();
        test_strbuff_addc();
        test_strbuff_addf();
        test_strbuff_adds();
        test_strbuff_end_with();
        test_strbuff_find();
        test_strbuff_len();
        test_strbuff_prefixb();
        test_strbuff_prefixs();
        test_strbuff_printc();
        test_strbuff_prints();
        test_strbuff_revert();
        test_strbuff_sanitize();
    }

    int r = UNITY_END();

    end        = clock();
    time_spent = ((double)(end - begin)) / ((double)(CLOCKS_PER_SEC));

    printf("Test duration:    %f seconds\n", time_spent);
    printf("strbuff version:  %d.%d.%d\n", STRBUFF_MAJOR, STRBUFF_MINOR, STRBUFF_FIX);
    printf("Branch name:      %s\n", STRBUFF_BRANCH_NAME);
    printf("Commit short SHA: %s\n", STRBUFF_COMMIT_SHORT_SHA);
    return r;
}
