// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Appends the contents of one string buffer to another.
 *
 * @param dest The destination string buffer.
 * @param src The source string buffer.
 * @return The length of the appended string.
 *
 * @headerfile #include "strbuff.h"
 *
 * @details If dest or src buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_addb(const strbuff *dest, const strbuff *src)
{
    strbuff_check_not_null(dest, return 0);
    strbuff_check_not_null(src, return 0);

    size_t _dest_len = strbuff_len(dest);
    size_t _src_len  = strbuff_len(src);

    /* Return if src has no valid string */
    strbuff_check_not_zero(_src_len, return 0);

    /* Check if there is enough room to copy the string */
    if ((_dest_len + _src_len) >= strbuff_capacity(dest)) {
        _src_len = strbuff_capacity(dest) - _dest_len - 1; /* -1 to append the null terminating char (AZT) */
    }

    (void)memmove(dest->str + _dest_len, src->str, _src_len);
    *(dest->str + _dest_len + _src_len) = 0;

    return _src_len;
}
