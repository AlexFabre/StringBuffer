// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Prefixes a string buffer with a single char.
 *
 * @param dest The destination string buffer.
 * @param src_char The source char to put in front.
 * @return The number of char added.
 *
 * @headerfile #include "strbuff.h"
 *
 * @details If dest buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_prefixc(const strbuff *dest, const char src_char)
{
    strbuff_check_not_null(dest, return 0);

    size_t _dest_len = strbuff_len(dest);

    /* Check that dest buffer has some content */
    if (_dest_len != 0) {
        /* Make sure there is enough room to copy the char */
        if ((_dest_len + 1) >= strbuff_capacity(dest)) {
            _dest_len -= 1;
        }

        (void)memmove(dest->str + 1, dest->str, _dest_len);
    }

    /* Copy the char at the begining */
    *(dest->str) = src_char;

    /* Make sure the string ends with a null terminating char */
    *(dest->str + _dest_len + 1) = 0;

    return 1;
}
