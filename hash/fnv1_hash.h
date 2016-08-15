/* Hash functions based on the fnv1 and fnv1a hash algorithms.
 * Courtesy : http://www.isthe.com/chongo/tech/comp/fnv/index.html
 */

#ifndef __FNV1_HASH_H__
#define __FNV1_HASH_H__

#include <stdio.h>
#include <stdint.h>

#define FNV1_32_OFFSET   (uint32_t) 2166136261
#define FNV1_32_PRIME    (uint32_t) 16777619

#define FNV1_16_MASK     (((uint32_t) 1 << 16) - 1)

uint32_t fnv1_hash_32(char* string);

uint32_t fnv1_hash_16(char* string);

uint32_t fnv1a_hash_32(char *string);

uint32_t fnv1a_hash_16(char *string);

#endif /* end of include guard: __FNV1_HASH_H__ */
