// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Prefixes a string buffer with the contents of a string literal.
 *
 * @param dest The destination string buffer.
 * @param src The source string to add in front.
 * @return The length of the source string copied into the buffer.
 *
 * @details If dest or src buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_prefixs(const strbuff *dest, const char *src_str)
{
    strbuff_check_not_null(dest, return 0);
    strbuff_check_not_null(src_str, return 0);

    size_t _dest_len = strbuff_len(dest);

    size_t      _src_len = 0;
    const char *s;

    /* Compute the size of the string to add */
    for (s = src_str; *s; s++) {
        if (_src_len == (strbuff_capacity(dest) - 1)) {
            break;
        }
        _src_len++;
    }

    /* If dest string buffer is not empty, move its content */
    if (_dest_len != 0) {
        /* If the two contents do not fit, the end will be lost */
        if (_dest_len + _src_len >= strbuff_capacity(dest)) {
            _dest_len = strbuff_capacity(dest) - 1 - _src_len;
        }
        memmove(dest->str + _src_len, dest->str, _dest_len);
    }

    /* Copy the new begining of dest string buffer */
    memcpy(dest->str, src_str, _src_len);
    *(dest->str + _src_len + _dest_len) = 0;

    return _src_len;
}
