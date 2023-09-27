// ======================================================================
// String Buffer Project - A safe string library for C
// Copyright (c) 2023 Alex Fabre
// [Released under MIT License. Please refer to license.txt for details]
// ======================================================================

#include "strbuff.h"

/**
 * Replace the destination buffer with a single char.
 *
 * @param dest The destination buffer.
 * @param src_str The source char.
 *
 * @return The number of char written to the destination string buffer.
 */
unsigned long strbuff_printc(const strbuff *dest, const char src_char)
{
    strbuff_check_not_null(dest, return 0);

    /* Check if there is enough room to copy the char and the null terminating char */
    if (strbuff_capacity(dest) < 2) {
        return 0;
    }

    dest->str[0] = src_char;
    dest->str[1] = 0;

    return 1;
}
