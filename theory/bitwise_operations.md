# Bitwise operations

* you should know many of the powers of 2 from (2^1 to 2^16 and 2^32)
* understand manipulation of bits with: `& | ^ ~ << >>`
* understand 2s and 1s complement
* round to next power of 2
```C
unsigned int roundUpToNextPowerOfTwo(unsigned int x)
{
  x--;
  x |= x >> 1;  // handle  2 bit numbers
  x |= x >> 2;  // handle  4 bit numbers
  x |= x >> 4;  // handle  8 bit numbers
  x |= x >> 8;  // handle 16 bit numbers
  x |= x >> 16; // handle 32 bit numbers
  x++;

  return x;

}

```

* swap two values
```C
void swap(int *a, int int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
```

* Absolute value of an integer
```C
int myAbs(int x)
{
  const int bit31 = x >> 31;
  return (x ^ bit31) - bit31;
}
```
