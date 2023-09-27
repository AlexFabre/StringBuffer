// ======================================================================
// String Buffer Project - A safe string library for C
// Copyright (c) 2023 Alex Fabre
// [Released under MIT License. Please refer to license.txt for details]
// ======================================================================

#include "strbuff.h"

/**
 * Find the first occurrence of a substring inside a string buffer.
 * @param dest The destination string buffer.
 * @param substring The substring to search for.
 * @param substring_len The length of the substring.
 * @return A pointer to the first occurrence of the substring if found,
 *         NULL otherwise.
 */
char *strbuff_find(const strbuff *dest, const strbuff *substring)
{
    /* Check if the destination buffer and source strings are not NULL. */
    strbuff_check_not_null(dest, return NULL);
    strbuff_check_not_null(substring, return NULL);

    size_t _substring_len = strbuff_len(substring);

    if (_substring_len > strbuff_capacity(dest)) {
        return NULL;
    }

    char       *_match_start;
    const char *_sub_letter  = substring->str;
    char       *_dest_letter = dest->str;

    /* First scan quickly through the two strings looking for a
     * single-character match.  When it's found, then compare the
     * rest of the substring.
     */

    if (*_sub_letter == 0) {
        return _dest_letter;
    }

    for (; (size_t)(_dest_letter - dest->str) < strbuff_capacity(dest); _dest_letter += 1) {
        if (*_dest_letter != *_sub_letter) {
            continue;
        }
        if ((strbuff_capacity(dest) - (size_t)(_dest_letter - dest->str)) < _substring_len) {
            return NULL;
        }
        _match_start = _dest_letter;
        while (1) {
            if (*_sub_letter == 0) {
                return _dest_letter;
            }
            if (*_match_start++ != *_sub_letter++) {
                break;
            }
        }
        _sub_letter = substring->str;
    }
    return NULL;
}
