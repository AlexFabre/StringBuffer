// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#ifndef _STRBUFF_PRINT_H_
#define _STRBUFF_PRINT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "strbuff_type.h"

/**
 * Replace the destination buffer with another buffer.
 *
 * @param dest The destination buffer.
 * @param src The source buffer.
 *
 * @return The number of char written to the destination buffer.
 */
unsigned long strbuff_printb(const strbuff *dest, const strbuff *src);

/**
 * Replace the destination buffer with a single char.
 *
 * @param dest The destination buffer.
 * @param src_str The source char.
 *
 * @return The number of char written to the destination string buffer.
 */
unsigned long strbuff_printc(const strbuff *dest, const char src_char);

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
unsigned long strbuff_printf(const strbuff *dest, const char *format, ...) __attribute__((format(printf, 2, 3)));

/**
 * Replace the destination buffer with the given source string.
 *
 * @param dest The destination buffer.
 * @param src_str The source string.
 *
 * @return The number of characters written to the destination string buffer.
 */
unsigned long strbuff_prints(const strbuff *dest, const char *src_str);

/* end of _STRBUFF_PRINT_H_ */
#ifdef __cplusplus
}
#endif
#endif
