# Queue

Queue: FIFO (first in first out)


## Implementation

### with linked-list

[Linked-List Implementation](http://www.cs.bu.edu/teaching/c/queue/linked-list/types.html)

### with fixed-sized array

This [article](https://www.cs.bu.edu/teaching/c/queue/array/types.html) is splendid!

## Questions and tips

- [x] Implement using fixed-sized array:
    - enqueue(value) - adds item at end of available storage
    - dequeue() - returns value and removes least recently added element
    - empty()
    - full()

- [x] Implement using linked-list, with tail pointer:
    - enqueue(value) - adds value at position at tail
    - dequeue() - returns value and removes least recently added element (front)
    - empty()
