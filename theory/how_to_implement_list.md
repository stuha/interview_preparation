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

- [x] implement (I did with tail pointer & without):
    - [x] size() - returns number of data elements in list
    - [x] empty() - bool returns true if empty
    - [x] value_at(index) - returns the value of the nth item (starting at 0 for first)
    - [x] push_front(value) - adds an item to the front of the list
    - [x] pop_front() - remove front item and return its value
    - [x] push_back(value) - adds an item at the end
    - [x] pop_back() - removes end item and returns its value
    - [x] front() - get value of front item
    - [x] back() - get value of end item
    - [x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
    - [x] erase(index) - removes node at given index
    - [x] value_n_from_end(n) - returns the value of the node at nth position from the end of the list
    - [x] reverse() - reverses the list
    - [x] remove_value(value) - removes the first item in the list with this value
