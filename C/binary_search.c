/*
 * Binary search
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

/*
 * return the index if found target
 * We assume the data type is `int`
 */
int binary_search(int *array, int target, int min, int max)
{
	int mark;

	do {
		mark = floor((min + max) / 2);
		if (array[mark] > target)
			max = mark - 1;
		else if (array[mark] < target)
			min = mark + 1;
		else
			return mark;
	} while (min <= max);

	return -1;
}

int binary_search_recursion(int *array, int target, int min, int max)
{
	if (min <= max) {
		int mark = floor((min + max) / 2);
		if (array[mark] > target)
			return binary_search_recursion(array, target, min, mark -1);
		else if (array[mark] < target)
			return binary_search_recursion(array, target, mark + 1, max);
		else
			return mark;
	}

	return -1;
}

void sorted_array_version()
{
	int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
		31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
		79, 83, 89, 97};

	int found = binary_search(a, 29, 0, 25);
	printf("29 at %d\n", found);

	int found2 = binary_search_recursion(a, 61, 0, 25);
	printf("61 at %d\n", found2);

	int found3 = binary_search(a, 62, 0, 25);
	printf("62 at %d\n", found3);

	int found4 = binary_search_recursion(a, 63, 0, 25);
	printf("63 at %d\n", found4);
}

int main(void)
{
	sorted_array_version();
	return 0;
}
