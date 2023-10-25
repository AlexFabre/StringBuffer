// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#include "strbuff.h"

/**
 * @brief Prefixes a string buffer with the contents of a string literal.
 *
 * @param dest The destination string buffer.
 * @param src The source string to add in front.
 * @return The length of the source string copied into the buffer.
 *
 * @headerfile #include "strbuff.h"
 *
 * @details If dest or src buffer pointer is null, then the function returns 0.
 */
// unsigned long strbuff_prefixs(const strbuff *dest, const char *src_str)
// {
//     strbuff_check_not_null(dest, return 0);
//     strbuff_check_not_null(src_str, return 0);

//     size_t _dest_len = strbuff_len(dest);

//     const char *s;

//     for (s = src_str; *s; s++) {
//         if (_dest_len == (strbuff_capacity(dest) - 1)) {
//             break;
//         }
//         *(dest->str + _dest_len) = *s;
//         _dest_len++;
//     }

//     *(dest->str + _dest_len) = 0;

//     return (size_t)(s - src_str);
// }
