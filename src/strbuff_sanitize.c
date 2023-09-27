// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Sanitizes a string buffer by setting remaining characters (beyond AZT) to 0.
 *
 * @param buff A pointer to a constant strbuff structure.
 * @return The number of characters available after the null terminating char (AZT).
 */
unsigned long strbuff_sanitize(const strbuff *buff)
{
    strbuff_check_not_null(buff, return 0);

    size_t _buff_len = strbuff_len(buff);

    /* Calculate the number of characters to be cleaned */
    unsigned long _char_to_clean = strbuff_capacity(buff) - _buff_len;

    (void)memset(buff->str + _buff_len, 0, _char_to_clean);

    /* Return the number of characters cleaned. */
    return _char_to_clean;
}
