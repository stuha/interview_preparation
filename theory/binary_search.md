# Binary Search

Binary search is an efficient algorithm for finding an item from an ordered list of items. It works by repeatedly dividing in balf the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

## pseudocode

1. Let `min = 1` where is the index `0` in an array and `max = n` where is the index `n - 1` in an array.
2. Guess the average of `max` and min, round down so that it is an integer.
3. If you guessed the number, stop. You found it!
4. If the guess was too low, set `min` to be one larger than the guess.
5. If the guess was too high, set `max` to be one smaller than the guess.
6. Go back to set two.

## Implementation
See `binary_search.c`.

# Binary Search Tree

## Properties

* The left subtree of a node only contains values that are less than or equal to the node's value.
* The right subtree of node only contains values that are greater than or equal to the node's value.
* Both left and right subtree of a node are also binary search trees.

