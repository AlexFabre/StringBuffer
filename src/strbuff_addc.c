// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Appends a single char to the end of a string buffer.
 *
 * @param dest The destination string buffer.
 * @param src_char The source char.
 * @return The number of char added.
 *
 * @details If dest buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_addc(const strbuff *dest, const char src_char)
{
    strbuff_check_not_null(dest, return 0);

    size_t _dest_len = strbuff_len(dest);

    /* Check if there is enough room to copy the char */
    if ((_dest_len + 1) >= strbuff_capacity(dest)) {
        return 0;
    }

    dest->str[_dest_len++] = src_char;
    dest->str[_dest_len]   = 0;

    return 1;
}
