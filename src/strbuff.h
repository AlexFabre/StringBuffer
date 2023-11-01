// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#ifndef _STRBUFF_H_
#define _STRBUFF_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "strbuff_add.h"
#include "strbuff_prefix.h"
#include "strbuff_print.h"

#include "strbuff_config.h"
#include "strbuff_type.h"
#include "strbuff_version.h"

#define STRBUFF_VERSION ((STRBUFF_MAJOR << 16) | (STRBUFF_MINOR << 8) | STRBUFF_FIX)

#ifndef strbuff_error_printf
#define strbuff_error_printf(...) ;
#endif

/**
 * @brief Macro to check if a pointer is not null. If the pointer is null, a specified action will be performed.
 *
 * @param ptr The pointer to check.
 * @param action_if_null The action to perform if the pointer is null.
 */
#define strbuff_check_not_null(ptr, action_if_null) \
    {                                               \
        if (ptr == NULL) {                          \
            action_if_null;                         \
        }                                           \
    }

/**
 * @brief Macro to check if an expression is not zero. If the expression is zero, a specified action will be performed.
 *
 * @param expr The expression to check.
 * @param action_if_zero The action to perform if the expression is zero.
 */
#define strbuff_check_not_zero(expr, action_if_zero) \
    {                                                \
        if (expr == 0) {                             \
            action_if_zero;                          \
        }                                            \
    }

/**
 * @brief Create a new local string buffer given a size and a default content
 *
 * This macro creates a new local string buffer with the specified size and default content.
 * It uses the provided `var` to name the variable and initializes it with the content.
 *
 * @param var The name of the variable to create
 * @param size The size of the string buffer (can be ommited when content is a string literal)
 * @param content The default content for the string buffer
 */
#define new_strbuff(var, size, content)                                            \
    char          strbuff_autogen_str_##var[size] = { content };                   \
    const strbuff var                             = {                              \
                                    .capacity = sizeof(strbuff_autogen_str_##var), \
                                    .str      = strbuff_autogen_str_##var,         \
    }

/**
 * @brief Create a new local string buffer given a char pointer and a size
 *
 * This macro defines a new string buffer with the specified capacity and initializes
 * it with the provided character pointer.
 *
 * @param var The name of the new string buffer variable
 * @param size The capacity of the string buffer
 * @param ptr The character pointer used to initialize the string buffer
 */
#define new_strbuff_from_ptr(var, ptr, size) \
    const strbuff var = {                    \
        .capacity = size,                    \
        .str      = ptr,                     \
    }

/**
 * @brief Returns the capacity of a string buffer.
 *
 * @param buff  The string buffer pointer.
 * @return The capacity of the string buffer.
 *
 * @note Example usage:
 *    strbuff my_buffer;
 *    // ...
 *    size_t capacity = strbuff_capacity(&my_buffer);
 */
#define strbuff_capacity(buff_ptr) ((buff_ptr)->capacity)

/**
 * @brief Reset to zero (AZT) all the buffer's string.
 *
 * @param buff  The string buffer pointer.
 *
 * @note Example usage:
 *    strbuff my_buffer;
 *    // ...
 *    strbuff_clear(&my_buffer);
 */
#define strbuff_clear(buff_ptr)    (void)memset((buff_ptr)->str, 0, (buff_ptr)->capacity)

#define strbuff_add(dest, src)     _Generic((src), int: strbuff_addc, char: strbuff_addc, char *: strbuff_adds, const char *: strbuff_adds, const strbuff *: strbuff_addb)(dest, src)

#define strbuff_prefix(dest, src)  _Generic((src), int: strbuff_prefixc, char: strbuff_prefixc, char *: strbuff_prefixs, const char *: strbuff_prefixs, const strbuff *: strbuff_prefixb)(dest, src)

#define strbuff_print(dest, src)   _Generic((src), int: strbuff_printc, char: strbuff_printc, char *: strbuff_prints, const char *: strbuff_prints, const strbuff *: strbuff_printb)(dest, src)

/**
 * @brief Checks that the buffer is ending with a specific frame.
 *
 * This function checks whether the buffer `buff` ends with the string `end`.
 *
 * @param buff Pointer to the buffer.
 * @param end Pointer to the string representing the specific frame.
 * @return Returns `true` if the buffer ends with the specific frame, else `false`.
 */
bool strbuff_ends_with(const strbuff *buff, const strbuff *end);

/**
 * Find the first occurrence of a substring inside a string buffer.
 * @param dest The destination string buffer.
 * @param substring The substring to search for.
 * @param substring_len The length of the substring.
 * @return A pointer to the first occurrence of the substring if found,
 *         NULL otherwise.
 */
char *strbuff_find(const strbuff *dest, const strbuff *substring);

/**
 * @brief Length of the string referenced by a string buffer.
 *
 * @param buff Reference to the string buffer.
 * @return The length of the string referenced by the string buffer.
 *
 * @details If the string buffer pointer is null, then the function returns 0.
 * @details If the string referenced by the buffer string is not null terminating (AZT), the function will return 0.
 */
size_t strbuff_len(const strbuff *buff);

/**
 * Reverses the contents of a string buffer.
 *
 * @param buff Pointer to the string buffer to be reversed.
 * @return The length of the string buffer.
 */
unsigned long strbuff_revert(const strbuff *buff);

/**
 * @brief Sanitizes a string buffer by setting remaining characters (beyond AZT) to 0.
 *
 * @param buff A pointer to a constant strbuff structure.
 * @return The number of characters available after the null terminating char (AZT).
 */
unsigned long strbuff_sanitize(const strbuff *buff);

/**
 * @brief Checks that the buffer is starting with a specific frame.
 *
 * This function checks whether the buffer `buff` starts with the string `start`.
 *
 * @param buff Pointer to the buffer.
 * @param start Pointer to the string representing the specific frame.
 * @return Returns `true` if the buffer starts with the specific frame, else `false`.
 */
bool strbuff_starts_with(const strbuff *buff, const strbuff *start);

/* end of _STRBUFF_H_ */
#ifdef __cplusplus
}
#endif
#endif
