// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#ifndef _STRBUFF_PREFIX_H_
#define _STRBUFF_PREFIX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "strbuff_type.h"

/**
 * @brief Prefixes a destination string buffer with another one.
 *
 * @param dest The destination string buffer.
 * @param src The source string buffer to put in front.
 * @return The length of the prefixed string.
 *
 * @details If dest or src buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_prefixb(const strbuff *dest, const strbuff *src);

/**
 * @brief Prefixes a string buffer with a single char.
 *
 * @param dest The destination string buffer.
 * @param src_char The source char to put in front.
 * @return The number of char added.
 *
 * @details If dest buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_prefixc(const strbuff *dest, const char src_char);

/**
 * @brief Add formatted data at the begining of a string buffer
 *
 * This function adds formatted data to the specified string buffer's begining using the provided format string and arguments.
 *
 * @param dest Pointer to the destination string buffer
 * @param format Format string used for formatting the data
 * @param ... Additional arguments used in the format string
 * @return The number of characters added to the string buffer, or 0 if an error occurred
 */
unsigned long strbuff_prefixf(const strbuff *dest, const char *format, ...) __attribute__((format(printf, 2, 3)));

/**
 * @brief Prefixes a string buffer with the contents of a string literal.
 *
 * @param dest The destination string buffer.
 * @param src The source string to add in front.
 * @return The length of the source string copied into the buffer.
 *
 * @details If dest or src buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_prefixs(const strbuff *dest, const char *src_str);

/* end of _STRBUFF_PREFIX_H_ */
#ifdef __cplusplus
}
#endif
#endif
