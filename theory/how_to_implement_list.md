# Implement a singly linked list in C

See detail article in [wikipedia](https://en.wikipedia.org/wiki/List_(abstract_data_type)). It's bad, don't read it. :(

## Implementation

Lists are typically implemented either as linked lists (either singly or doubly linked) or as arrays, usually variable length or dynamic arrays.

### structure

```C
struct node {
        int data;
        struct node *next;
};
```

### functions

* `size`
* `empty`
* `push_front`
* `pop_front`
* `push_back`
* `pop_back`
* `front`
* `back`
* `insert`
* `erase`
* `value_n_from_end`
* `reverse`
* `remove_value`

### Questions and tips

