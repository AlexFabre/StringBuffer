// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * Reverses the contents of a string buffer.
 *
 * @param buff Pointer to the string buffer to be reversed.
 * @return The length of the string buffer.
 */
unsigned long strbuff_revert(const strbuff *buff)
{
    strbuff_check_not_null(buff, return 0);

    size_t _buff_len = strbuff_len(buff);

    // Reverse the characters in the buffer one by one
    for (size_t i = 0; i < (_buff_len / 2); i++) {

        char tmp = *(buff->str + i);

        *(buff->str + i) = *(buff->str + _buff_len - i - 1);

        *(buff->str + _buff_len - 1 - i) = tmp;
    }

    return _buff_len;
}
