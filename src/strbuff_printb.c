// ======================================================================
// String Buffer Project - A safe string library for C
// Copyright (c) 2023 Alex Fabre
// [Released under MIT License. Please refer to license.txt for details]
// ======================================================================

#include "strbuff.h"

/**
 * Replace the destination buffer with another buffer.
 *
 * @param dest The destination buffer.
 * @param src The source buffer.
 *
 * @return The number of char written to the destination buffer.
 */
unsigned long strbuff_printb(const strbuff *dest, const strbuff *src)
{
    strbuff_check_not_null(dest, return 0);
    strbuff_check_not_null(src, return 0);

    size_t _src_len = strbuff_len(src);

    if (strbuff_capacity(dest) <= _src_len) {
        _src_len = strbuff_capacity(dest) - 1;
    }

    memcpy(dest->str, src->str, _src_len);
    *(dest->str + _src_len) = 0;

    return _src_len;
}
