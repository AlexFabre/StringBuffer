// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Checks that the buffer is ending with a specific frame.
 *
 * This function checks whether the buffer `buff` ends with the string `end`.
 *
 * @param buff Pointer to the buffer.
 * @param end Pointer to the string representing the specific frame.
 * @return Returns `true` if the buffer ends with the specific frame, else `false`.
 */
bool strbuff_ends_with(const strbuff *buff, const strbuff *end)
{
    strbuff_check_not_null(buff, return false);
    strbuff_check_not_null(end, return false);

    const char *_end_c  = (end->str + strbuff_len(end));
    const char *_buff_c = (buff->str + strbuff_len(buff));

    while (_end_c >= end->str) {
        if (*_end_c != *_buff_c) {
            return false;
        }
        _end_c--;
        _buff_c--;
    }
    return true;
}
