// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "../lib/unity/unity.h"

#include "../src/strbuff.h"

/* Minimum length of the strings generated for the test */
#define TEST_MIN_STRING_LEN 100

/* Length in bytes of the two buffers that will be used into the unit tests */
#define TEST_BUFFER_SIZE    (8 * 1024)

static_assert(TEST_BUFFER_SIZE > (2 * TEST_MIN_STRING_LEN), "Unit test buffer's size must be at least 100 bytes");

/* Number of time each unit test will be run
 * The buffers content are generated with random bytes.
 * More loop ensure more cases */
#define UNIT_TEST_LOOP 100

/* Buffer mainly used as destination buffer in unit tests */
extern const strbuff buffer1;

/* Buffer mainly used as source buffer in unit tests */
extern const strbuff buffer2;

/**
 * Generate a random sized string that fits in the destination buffer.
 *
 * @param dest_buffer The destination buffer where the generated string will be stored.
 * @param dest_buffer_size The size of the destination buffer.
 */
void rand_string(char dest_buffer[], size_t dest_buffer_size);

/**
 * Generate a fixed length string into a destination buffer.
 *
 * @param dest_buffer The destination buffer where the generated string will be stored.
 * @param dest_buffer_size The size of the destination buffer.
 * @param string_length The desired length of the generated string.
 */
void rand_string_fixed_length(char dest_buffer[], size_t dest_buffer_size, size_t string_length);

/**
 * Generate a random character.
 *
 * @param can_be_null A boolean parameter indicating whether the result char can be null or not.
 * @return The randomly generated character.
 */
char rand_char(bool can_be_null);

/**
 * Generates a random positive integer between the given minimum and maximum bounds.
 *
 * @param min The minimum bound for the generated random number.
 * @param max The maximum bound for the generated random number.
 *
 * @return The randomly generated positive integer.
 */
unsigned long rand_uint(unsigned long min, unsigned long max);

/* All the unit tests functions to be called */

void test_strbuff_addb(void);
void test_strbuff_addc(void);
void test_strbuff_addf(void);
void test_strbuff_adds(void);
void test_strbuff_end_with(void);
void test_strbuff_find(void);
void test_strbuff_len(void);
void test_strbuff_prefixb(void);
void test_strbuff_prefixs(void);
// void test_strbuff_printb(void);
void test_strbuff_printc(void);
// void test_strbuff_printf(void);
void test_strbuff_prints(void);
void test_strbuff_revert(void);
void test_strbuff_sanitize(void);
// void test_strbuff_starts_with(void);
