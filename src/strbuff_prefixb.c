// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Prefixes a destination string buffer with another one.
 *
 * @param dest The destination string buffer.
 * @param src The source string buffer to put in front.
 * @return The length of the prefixed string.
 *
 * @details If dest or src buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_prefixb(const strbuff *restrict dest, const strbuff *restrict src)
{
    strbuff_check_not_null(dest, return 0);
    strbuff_check_not_null(src, return 0);

    size_t _dest_len = strbuff_len(dest);
    size_t _src_len  = strbuff_len(src);

    /* Return if src has no valid string */
    strbuff_check_not_zero(_src_len, return 0);

    /* Check if string to add can fit in destination buffer */
    if (_src_len < strbuff_capacity(dest)) {
        /* Check that dest buffer has some content */
        if (_dest_len != 0) {
            /* Check if both string summed exceed dest buffer limit */
            if ((_dest_len + _src_len) >= strbuff_capacity(dest)) {
                /* If so, discard the end of dest buffer content */
                _dest_len = strbuff_capacity(dest) - _src_len - 1;
            }
            /* Move dest buffer content to let source string fit at the begining */
            (void)memmove(dest->str + _src_len, dest->str, _dest_len);
        }
    } else {
        /* String to add is too big. Strip it and discard dest buffer content */
        _src_len = strbuff_capacity(dest) - 1;
    }

    (void)memmove(dest->str, src->str, _src_len);
    *(dest->str + _dest_len + _src_len) = 0;

    return _src_len;
}
