# The theory of vector

The vector also called dynamic array which is not implemented in C. But, we can use "`alloc`" functions to implement it.
Ok, let's see it.

## The important points of vector

* the maximum logical size is unknown, or difficult to calculate, before the array is allocated
* it is considered that a maximum logical size given by a specification is likely to change
* the amortized cost of resizing a dynamic array does not significantly affect performance or responsiveness

## How to implement it in C

### structure

```C
struct vector {
        int *data;
        int size;
        int capacity;
};
```

### functions
* `size`
* `capacity`
* `is_empty`
* `at`
* `push`
* `insert`
* `prepend`
* `pop`
* `delete`
* `remove`
* `find`
* `resize`

### Questions and tips

- [x] Implement a vector (mutable array with automatic resizing):
    - [x] Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
    - [x] new raw data array with allocated memory
        - can allocate int array under the hood, just not use its features
        - start with 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128
    - [x] size() - number of items
    - [x] capacity() - number of items it can hold
    - [x] is_empty()
    - [x] at(index) - returns item at given index, blows up if index out of bounds
    - [x] push(item)
    - [x] insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
    - [x] prepend(item) - can use insert above at index 0
    - [x] pop() - remove from end, return value
    - [x] delete(index) - delete item at index, shifting all trailing elements left
    - [x] remove(item) - looks for value and removes index holding it (even if in multiple places)
    - [x] find(item) - looks for value and returns first index with that value, -1 if not found
    - [x] resize(new_capacity) // private function
        - when you reach capacity, resize to double the size
        - when popping an item, if size is 1/4 of capacity, resize to half

  - [x] Time
      - O(1) to add/remove at end (amortized for allocations for more space), index, or update
      - O(n) to insert/remove elsewhere
  - [x] Space
      - contiguous in memory, so proximity helps performance
      - space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)

### Codes
It's in `show-me-codes/C/vector.c`.
