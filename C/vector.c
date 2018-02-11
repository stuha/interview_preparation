/*
 * Implementation of vector in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VCAP 16
#define FAC  2


struct vector {
	int *data;
	int size;
	int capacity;
};


int resize(struct vector *);


struct vector *init()
{
	struct vector *vtmp;
	vtmp = malloc(sizeof(struct vector));
	memset(vtmp, 0, sizeof(struct vector));

	vtmp->data = calloc(VCAP, sizeof(int));
	vtmp->size = 0;
	vtmp->capacity = VCAP;

	return vtmp;
}

int size(struct vector *da)
{
	return da->size;
}

int capacity(struct vector *da)
{
	return da->capacity;
}

int is_empty(struct vector *da)
{
	if (!da->size)
		return 1;
	else
		return 0;
}

int at(struct vector *da, int index)
{
	if (index > da->capacity)
		exit(1);
	else
		return *(da->data + index);
}

int push(struct vector *da, int item)
{
#if 0
	int *redata;

	if (da->size == da->capacity) {
		redata = realloc(da->data, da->capacity * FAC * sizeof(int));
		if (!redata)
			exit(1);
		if (redata != da->data) {
			memset(redata, 0, da->capacity * FAC * sizeof(int));
			memcpy(redata, da->data, da->capacity * sizeof(int));
			da->data = redata;
		}

		da->capacity *= FAC;
	}
#endif
	resize(da);

	*(da->data + da->size) = item;
	da->size++;

	return 0;
}

int insert(struct vector *da, int index, int item)
{
#if 0
	int *redata;

	if (da->size == da->capacity) {
		redata = realloc(da->data, da->capacity * FAC * sizeof(int));
		if (!redata)
			exit(1);
		if (redata != da->data) {
			memset(redata, 0, da->capacity * FAC * sizeof(int));
			memcpy(redata, da->data, da->capacity * sizeof(int));
			da->data = redata;
		}

		da->capacity *= FAC;
	}
#endif
	resize(da);

	for (int i = da->size; i >= index; i--)
		*(da->data + i + 1) = *(da->data + i);

	*(da->data + index) = item;
	da->size++;

	return 0;
}

int prepend(struct vector *da, int item)
{
	return insert(da, 0, item);
}

int pop(struct vector *da)
{
#if 0
	int tmp = *(da->data + da->size - 1);
	int *redata;

	if (da->size == da->capacity / 2 + 1) {
		int recap = da->capacity / 2 * sizeof(int);

		redata = realloc(da->data, recap);
		if (!redata)
			exit(1);
		if (redata != da->data) {
			memset(redata, 0, recap);
			memcpy(redata, da->data, recap);
			da->data = redata;
		}

		da->capacity /= 2;
	} else {
		*(da->data + da->size - 1) = 0;
	}
#endif
	da->size--;

	resize(da);

	return *(da->data + da->size - 1);
}

/* return what deleted */
int delete(struct vector *da, int index)
{
#if 0
	int *redata;

	if (da->size == da->capacity / 2 + 1) {
		int recap = da->capacity / FAC * sizeof(int);

		redata = realloc(da->data, recap);
		if (!redata)
			exit(1);
		if (redata != da->data) {
			memset(redata, 0, recap);
			memcpy(redata, da->data, recap);
			da->data = redata;
		}

		da->capacity /= FAC;
	}
#endif
	int tmp = *(da->data + index);
	for (int i = index; i < da->size; i++)
		*(da->data + i) = *(da->data + i + 1);

	da->size--;

	resize(da);

	return tmp;
}

int find_item(struct vector *da, int item)
{
	int i;

	for (i = 0; i < da->size; i++) {
		if (*(da->data + i) == item)
			return i;
	}

	return -1;
}

int remove_item(struct vector *da, int item)
{
	int i;
	int n;

refor:
	for (i = 0; i < da->size; i++) {
		if (*(da->data + i) == item) {
			delete(da, i);
			n++;
			goto refor;
		}
	}

	return n;
}

int resize(struct vector *da)
{
	int *redata;
	int recap;
	/*
	 * reach capacity, resize to double the size
	 *
	 * when popping an item, if size is 1/4 of capacity,
	 * resize to half
	 */

	if (da->size == da->capacity) {
		recap = da->capacity * FAC * sizeof(int);
		da->capacity *= FAC;
	} else if (da->capacity > VCAP && da->size == da->capacity / 4) {
		recap = da->capacity / FAC * sizeof(int);
		da->capacity /= FAC;
	} else
		/* don't need realloc */
		return da->capacity;

	redata = realloc(da->data, recap);
	if (!redata)
		exit(1);
	if (redata != da->data) {
		memset(redata, 0, recap);
		memcpy(redata, da->data, recap);
		da->data = redata;
	}

	return da->capacity;
}



/* test functions */
void show_all(struct vector *da)
{
	for (int i = 0; i < size(da); i++)
		printf("at%03d = %03d\n", i, at(da, i));
}

void show_top_ten(struct vector *da)
{
	if (da->size < 10)
		show_all(da);
	else
		for (int i = 0; i < 10; i++)
			printf("at%03d = %03d\n", i, at(da, i));
}

void show_last_ten(struct vector *da)
{
	if (da->size < 10)
		show_all(da);
	else
		for (int i = da->size - 10; i < da->size; i++)
			printf("at%03d = %03d\n", i, at(da, i));
}

void test_push_pop(struct vector *da)
{
	int i, j;
	for (i = 0; i < 1000; i++)
		push(da, i);

	printf("after push:\n");
	show_top_ten(da);
	show_last_ten(da);
	for (i = 0; i < 5; i++)
		pop(da);
	printf("\nafter pop:\n");
	show_last_ten(da);
}

void test_all(struct vector *da)
{
	test_push_pop(da);
	printf("\ntest insert:\n");
	insert(da, 3, 888);
	insert(da, 7, 999);
	show_top_ten(da);
	insert(da, 995, 111);
	insert(da, 997, 222);
	show_last_ten(da);

	printf("\ntest delete\n");
	delete(da, 991);
	delete(da, 993);
	show_last_ten(da);

	printf("\nfound 500 at %03d\n", find_item(da, 500));
}

int main(void)
{
	struct vector *testv;
	testv = init();

	test_all(testv);

	free(testv->data);
	free(testv);
	return 0;
}
