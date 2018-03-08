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

/*
get_node_count

print_values

delete_tree

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

	return 0;
}
