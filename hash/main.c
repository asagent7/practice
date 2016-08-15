/* Hash functions based on the fnv1 and fnv1a hash algorithms.
 * Courtesy : http://www.isthe.com/chongo/tech/comp/fnv/index.html
 */

#include "fnv1_hash.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./fnv32_hash string\n");
        return 1;
    }

    printf("fnv1_32 hash value (in hex)  = %x\n", fnv1_hash_32(argv[1]));
    printf("fnv1_16 hash value (in hex)  = %x\n", fnv1_hash_16(argv[1]));
    printf("fnv1a_32 hash value (in hex) = %x\n", fnv1a_hash_32(argv[1]));
    printf("fnv1a_16 hash value (in hex) = %x\n", fnv1a_hash_16(argv[1]));
    return 0;
}
