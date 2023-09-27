// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Checks that the buffer is starting with a specific frame.
 *
 * This function checks whether the buffer `buff` starts with the string `start`.
 *
 * @param buff Pointer to the buffer.
 * @param start Pointer to the string representing the specific frame.
 * @return Returns `true` if the buffer starts with the specific frame, else `false`.
 */
bool strbuff_starts_with(const strbuff *buff, const strbuff *start)
{
    strbuff_check_not_null(buff, return false);
    strbuff_check_not_null(start, return false);

    return (memcmp(buff->str, start->str, strbuff_len(start)) == 0);
}
