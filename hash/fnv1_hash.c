/* Hash functions based on the fnv1 and fnv1a hash algorithms.
 * Courtesy : http://www.isthe.com/chongo/tech/comp/fnv/index.html
 */

#include "fnv1_hash.h"

uint32_t fnv1_hash_32(char *string)
{
    uint32_t hash_value = FNV1_32_OFFSET;

    for (uint32_t i = 0; string[i] != 0; i++)
    {
        hash_value *= FNV1_32_PRIME;
        hash_value ^= (uint32_t) string[i];
    }

    return hash_value;
}

uint16_t fnv1_hash_16(char *string)
{
    uint32_t hash_value = fnv1_hash_32(string);
    hash_value = (hash_value >> 16) ^ (hash_value & FNV1_16_MASK);

    return (uint16_t)hash_value;
}

uint8_t fnv1_hash_8(char *string)
{
    uint32_t hash_value = fnv1_hash_32(string);
    hash_value = (hash_value >> 8) ^ (hash_value & FNV1_8_MASK);

    return (uint8_t)hash_value;
}

uint32_t fnv1a_hash_32(char *string)
{
    uint32_t hash_value = FNV1_32_OFFSET;

    for (uint32_t i = 0; string[i] != 0; i++)
    {
        hash_value ^= (uint32_t) string[i];
        hash_value *= FNV1_32_PRIME;
    }

    return hash_value;
}

uint16_t fnv1a_hash_16(char *string)
{
    uint32_t hash_value = fnv1a_hash_32(string);
    hash_value = (hash_value >> 16) ^ (hash_value & FNV1_16_MASK);

    return (uint16_t)hash_value;
}

uint8_t fnv1a_hash_8(char *string)
{
    uint32_t hash_value = fnv1a_hash_32(string);
    hash_value = (hash_value >> 8) ^ (hash_value & FNV1_8_MASK);

    return (uint8_t)hash_value;
}
