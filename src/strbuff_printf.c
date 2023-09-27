// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Print formatted data to a string buffer
 *
 * This function prints formatted data to the specified string buffer using the provided format string and arguments.
 *
 * @param dest Pointer to the destination string buffer
 * @param format Format string used for formatting the data
 * @param ... Additional arguments used in the format string
 * @return The number of characters printed to the string buffer, or 0 if an error occurred
 */
unsigned long strbuff_printf(const strbuff *dest, const char *format, ...)
{
    strbuff_check_not_null(dest, return 0);
    strbuff_check_not_null(format, return 0);

    va_list args;
    va_start(args, format);
    int n = vsnprintf(dest->str, dest->capacity, format, args);
    va_end(args);

    if (n < 0) {
        strbuff_error_printf("var arg error %d", n);
        strbuff_sanitize(dest);
        return 0;
    } else if ((unsigned long)n >= dest->capacity) {
        strbuff_error_printf("not enough room %zu <= %d", dest->capacity, n);
        return dest->capacity - 1;
    }

    return (unsigned long)n;
}
