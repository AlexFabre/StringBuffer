// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Length of the string referenced by a string buffer.
 *
 * @param buff Reference to the string buffer.
 * @return The length of the string referenced by the string buffer.
 *
 * @headerfile #include "strbuff.h"
 *
 * @details If the string buffer pointer is null, then the function returns 0.
 * @details If the string referenced by the buffer string is not null terminating (AZT), the function will return 0.
 */
size_t strbuff_len(const strbuff *buff)
{
    strbuff_check_not_null(buff, return 0);

    const char *s;

    for (s = buff->str; *s; s++) {
        if ((unsigned)(s - buff->str) == (strbuff_capacity(buff) - 1)) {
            /* The null terminating char was not found within the string total size
             * Write a null terminating char at the begining for safety */
            *buff->str = 0;
            return 0;
        }
    }

    return (size_t)(s - buff->str);
}
