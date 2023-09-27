// ======================================================================
// String Buffer Project - A safe string library for C
// Copyright (c) 2023 Alex Fabre
// [Released under MIT License. Please refer to license.txt for details]
// ======================================================================

#include "strbuff.h"

/**
 * Replace the destination buffer with the given source string.
 *
 * @param dest The destination buffer.
 * @param src_str The source string.
 *
 * @return The number of characters written to the destination string buffer.
 */
unsigned long strbuff_prints(const strbuff *dest, const char *src_str)
{
    /* Check if the destination buffer and source strings are not NULL. */
    strbuff_check_not_null(dest, return 0);
    strbuff_check_not_null(src_str, return 0);

    const char *s;

    /* Pointer to the start of the destination string buffer. */
    char *d = dest->str;

    for (s = src_str; *s; s++) {
        /* If the position in the source string is equal to the capacity
         * of the destination string buffer minus 1, break the loop
         * to ensure the destination string buffer does not overflow. */
        if ((size_t)(s - src_str) == (strbuff_capacity(dest) - 1)) {
            break;
        }

        *d = *s;
        d++;
    }

    /* Null-terminate the destination string buffer. */
    *d = 0;

    /* Returns the number of characters written on the destination string buffer. */
    return (size_t)(s - src_str);
}
