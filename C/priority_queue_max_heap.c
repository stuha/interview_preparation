/*
 * max heap
 */

/*
 * insert
 * sift_up
 * get_max
 * get_size
 * is_empty
 * extract_max
 * sift_down
 * remove(i)
 * heapify
 * heap_sort
 *
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef int heap_type;

/* we assume the heap is small and static */
#define CAPACITY 100

struct max_heap {
	size_t size;
	heap_type element[CAPACITY + 1];
	/* current capacity */
	size_t capacity;
};



