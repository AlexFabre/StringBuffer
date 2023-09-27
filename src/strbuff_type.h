// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#ifndef _STRBUFF_TYPE_H_
#define _STRBUFF_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

/**
 * @brief Buffer representation of a char string
 * @details Safe way to mainpulate a char array with its capacity
 */
typedef struct {
    /* Total capacity of the char array (including the null terminating char) */
    const size_t capacity;
    /* Pointer to the char array start */
    char *const  str;
} strbuff;

/* end of _STRBUFF_TYPE_H_ */
#ifdef __cplusplus
}
#endif
#endif
