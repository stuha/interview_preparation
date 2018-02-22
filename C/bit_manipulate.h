/*
 * Bit manipulation
 * * can only be used on integrals, no floats!
 */

#include <stdbool.h>

#define SET_BIT(x, pos)	    (x | (1 << pos))
#define CLEAR_BIT(x, pos)   (x & (~(1 << pos)))
#define FLIP_BIT(x, pos)    (x ^ (1 << pos))
#define IS_BIT_SET(x, pos)  ((x >> pos) & 1)

#define MODIFY_BIT(x, pos, state) ((x & (~(1 << pos))) | (~state & (1 << pos)))


#define IS_EVEN(x) (((x & 1) == 0) ? true : false)

#define IS_POWER2(x) (x && !(x & (x - 1)))


#define MIN(x, y) (y ^ ((x ^ y) & -(x < y)))
#define MAX(x, y) (x ^ ((x ^ y) & -(x < y)))

/* with xor */
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

/* with subtraction and addition */
#define SWAP(a, b) ((&(a) == &(b)) || \
			(((a) -= (b)), ((b) += (a)), ((a) = (b) - (a))))


/* more hascks in https://graphics.stanford.edu/~seander/bithacks.html#OperationCounting */
