/*
 * Binary search tree
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int value_type;

/* Implementation */

/* structure */
struct bst_node {
	//int key;
	value_type value;
	struct bst_node *left;
	struct bst_node *right;
};

struct bst {
	struct bst_node *root;
	int node_size;
	int bst_height;
};

/* functions */
/* recursion */
//Rsearch()
/* iteration */
//Isearch()

struct bst_node *insert(value_type value, struct bst_node *root)
{
	if (root == NULL) {
		struct bst_node *nt = malloc(sizeof(struct bst_node));
		if (!nt)
			exit(1);

		nt->value = value;
		nt->left = NULL;
		nt->right = NULL;

		return nt;
	}

	if (root->value >= value)
		root->left = insert(value, root->left);
	else if (root->value <= value)
		root->right = insert(value, root->right);

	return root;
}

int get_node_count(struct bst_node *root)
{
	if (root == NULL)
		return 0;

	return 1 + get_node_count(root->left) + get_node_count(root->right);
}

void delete_tree(struct bst_node *root)
{
	if (root == NULL) return;

	delete_tree(root->left);
	delete_tree(root->right);
	free(root);
}

void print_values(struct bst_node *root)
{
	if (root == NULL)
		return;

	print_values(root->left);
	printf("%d\n", root->value);
	print_values(root->right);
}
/*
get_height

get_min

get_max

is_binary_search_tree

delete_value

get_successor

*/




/* For testing */

/* test cases */

int main(void)
{
	struct bst_node *bst_test;
	bst_test = insert(10, bst_test);
	bst_test = insert(20, bst_test);

	printf("count: %d\n", get_node_count(bst_test));
	printf("-------------------------\n");
	print_values(bst_test);

	delete_tree(bst_test);
	return 0;
}
