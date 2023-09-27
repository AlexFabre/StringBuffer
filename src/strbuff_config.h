// ==========================================
//   String Buffer Project - A safe string library for C
//   Copyright (c) 2023 Alex Fabre
//   [Released under MIT License. Please refer to license.txt for details]
// ==========================================

#ifndef _STRBUFF_CONFIG_H_
#define _STRBUFF_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef strbuff_error_printf
/* External printf-like function to output strbuff errors */
#define strbuff_error_printf(format, ...) printf("strbuff:(%s,%d):" format "\n", __func__, __LINE__, __VA_ARGS__)
#endif

/* end of _STRBUFF_CONFIG_H_ */
#ifdef __cplusplus
}
#endif
#endif
