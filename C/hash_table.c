/*
 * The implementation of hash d
 * (implement with array using linear probing)
 *
 * Reference to https://github.com/jwasham/practice-c/tree/master/hash_table
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define DICT_SIZE 100
char* k_dummy = "<dummy>";

typedef struct key_value_t {
	char *key;
	char *value;
} key_value;

typedef struct dict_t {
	key_value **data;
	int size;
} dict, *dictp;

enum {
	ERROR_ALLOC = 1,
	ERROR_DICT
};

//typedef enum {true, false} bool;

dict *init(const int size)
{
	dictp dict_tmp = malloc(sizeof(dict));
	if (!dict_tmp)
		exit(ERROR_ALLOC);

	dict_tmp->data = malloc(sizeof(key_value) * size);
	if (!dict_tmp->data)
		exit(ERROR_ALLOC);

	for (int i = 0; i < size; i++) {
		dict_tmp->data[i] = NULL;
	}

	dict_tmp->size = size;

	return dict_tmp;
}

void destroy(dictp d)
{
	for(int i = 0; i < d->size; ++i) {
		if (d->data[i]) {
			free(d->data[i]->key);
			free(d->data[i]->value);
			free(d->data[i]);
		}
	}

	free(d->data);
	free(d);
}

int hash(const char *key, const int m)
{
	int hash = 0;

	for (int i = 0; i < key[i] != '\0'; ++i)
		hash = hash * 31 + key[i];

	return abs(hash % m);
}

bool add(dictp d, const char *key, const key_value *obj)
{
	int index = hash(key, DICT_SIZE);
	int original_index = index;
	bool found = false;
	int dummy_index = -1;

	while (d->data[index] != NULL) {
		if (strcmp(d->data[index]->key, key) == 0) {
			found = true;
			break;

		} else if (strcmp(d->data[index]->key, k_dummy) == 0) {
			dummy_index = index;
		}

		index = (index + 1) % d->size;
		if (index == original_index)
			return false;
	}

	if (! found && dummy_index != -1) {
		// use dummy index to insert
		index = dummy_index;
	}

	if (d->data[index] == NULL) {
		d->data[index] = malloc(sizeof(key_value));

	} else {
		free(d->data[index]->key);
		free(d->data[index]->value);

	}

	d->data[index]->key = strdup(obj->key);
	d->data[index]->value = strdup(obj->value);

	return true;
}

bool exists(dictp d, char *key)
{
	int index = hash(key, DICT_SIZE);
	int original_index = index;
	bool found = false;

	while (d->data[index] != NULL) {
		if (strcmp(d->data[index]->key, key) == 0) {
			found = true;
			break;
		}
		index = (index + 1) % d->size;

		if (index == original_index)
			break;
	}

	return found;
}

char* get(const dictp d, const char* key)
{
	int index = hash(key, d->size);
	int original_index = index;

	while (d->data[index] != NULL) {
		if (strcmp(d->data[index]->key, key) == 0)
			return d->data[index]->value;

		index = (index + 1) % d->size;
		if (index == original_index)
			break;
	}

	return NULL;
}

void delete(dictp d, const char* key)
{
	int index = hash(key, d->size);
	int original_index = index;

	while (d->data[index] != NULL) {
		if (strcmp(d->data[index]->key, key) == 0) {
			free(d->data[index]->key);
			free(d->data[index]->value);
			d->data[index]->key = strdup(k_dummy);
			d->data[index]->value = strdup("");
			break;
		}
		index = (index + 1) % d->size;
		if (index == original_index)
			return;
	}
}



/* Test case */
void print_debug(dictp d)
{
	for (int i = 0; i < d->size; ++i) {
		if (d->data[i] == NULL)
			printf("%d:\n", i);
		else
			printf("%s: %s\n", d->data[i]->key, d->data[i]->value);
	}

	printf("===================\n");
}


void test_exists() {
	dictp states = init(DICT_SIZE);

	assert(exists(states, "Texas") == false);

	key_value tx = {"Texas", "Austin"};
	add(states, "Texas", &tx);

	assert(exists(states, "Texas") == true);

	print_debug(states);

	destroy(states);
}

void test_add_get() {
	dictp states = init(DICT_SIZE);

	key_value la = {"Louisiana", "Baton Rouge"};
	add(states, "Louisiana", &la);

	key_value me = {"Maine", "Augusta"};
	add(states, "Maine", &me);

	char* capital1 = get(states, "Louisiana");
	assert(strcmp(capital1, "Baton Rouge") == 0);

	// add LA again, with new capital
	key_value la2 = {"Louisiana", "New Orleans"};
	add(states, "Louisiana", &la2);

	// now capital should be Nawlins
	char* capital2 = get(states, "Louisiana");
	assert(strcmp(capital2, "New Orleans") == 0);

	print_debug(states);

	destroy(states);
}

void test_add_remove() {
	dictp states = init(DICT_SIZE);

	key_value ca = {"California", "Sacramento"};
	add(states, "California", &ca);

	assert(exists(states, "California") == true);

	delete(states, "California");

	assert(exists(states, "California") == false);

	print_debug(states);

	destroy(states);
}

void run_all_tests() {
	test_exists();
	test_add_get();
	test_add_remove();
}

int main(void)
{
	run_all_tests();
	return 0;
}
