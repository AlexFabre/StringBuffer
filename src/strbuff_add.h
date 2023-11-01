// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#ifndef _STRBUFF_ADD_H_
#define _STRBUFF_ADD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "strbuff_type.h"

/**
 * @brief Appends the contents of one string buffer to another.
 *
 * @param dest The destination string buffer.
 * @param src The source string buffer.
 * @return The length of the appended string.
 *
 * @details If dest or src buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_addb(const strbuff *dest, const strbuff *src);

/**
 * @brief Appends a single char to the end of a string buffer.
 *
 * @param dest The destination string buffer.
 * @param src_char The source char.
 * @return The number of char added.
 *
 * @details If dest buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_addc(const strbuff *dest, const char src_char);

/**
 * @brief Add formatted data to a string buffer
 *
 * This function adds formatted data to the specified string buffer using the provided format string and arguments.
 *
 * @param dest Pointer to the destination string buffer
 * @param format Format string used for formatting the data
 * @param ... Additional arguments used in the format string
 * @return The number of characters added to the string buffer, or 0 if an error occurred
 */
unsigned long strbuff_addf(const strbuff *dest, const char *format, ...) __attribute__((format(printf, 2, 3)));

/**
 * @brief Appends the contents of one string literal to a string buffer.
 *
 * @param dest The destination string buffer.
 * @param src The source string.
 * @return The length of the source string copied into the buffer.
 *
 * @details If dest or src buffer pointer is null, then the function returns 0.
 */
unsigned long strbuff_adds(const strbuff *dest, const char *src_str);

/* end of _STRBUFF_ADD_H_ */
#ifdef __cplusplus
}
#endif
#endif
