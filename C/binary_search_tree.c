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

int obtain_max(int v1, int v2)
{
	return v1 >= v2 ? v1 : v2;
}

int get_height(struct bst_node *root)
{
	if (root == NULL)
		return 0;

	return 1 + obtain_max(get_height(root->left), get_height(root->right));
}

/* return the most left value */
int get_min(struct bst_node *root)
{
	if (root == NULL)
		return -1;

	struct bst_node *current = root;
	while (current->left != NULL)
		current = current->left;

	return current->value;
}

int get_max(struct bst_node *root)
{
	if (root == NULL)
		return -1;

	struct bst_node *current = root;
	while (current->right != NULL)
		current = current->right;

	return current->value;
}

bool is_binary_search_tree(struct bst_node *root, int min_value, int max_value)
{
	if (root == NULL) return true;
	if (root->value < min_value || root->value > max_value) return false;

	return is_binary_search_tree(root->left, min_value, root->value - 1) &&
		is_binary_search_tree(root->right, root->value + 1, max_value);
}

/* more complicated than other function */
struct bst_node *delete_value(struct bst_node *root, int value)
{
	if (root == NULL) return root;

	if (root->value > value)
		root->left = delete_value(root->left, value);
	else if (root-> value < value)
		root->right = delete_value(root->right, value);
	else {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		} else if (root->left == NULL) {
			struct bst_node *tmp = root;
			root = root->right;
			free(tmp);
		} else if (root->right == NULL) {
			struct bst_node *tmp = root;
			root = root->left;
			free(tmp);
		} else {
			/* get the minimal value in the right subtree */
			int right_min = get_min(root->right);
			root->value = right_min;
			root->right = delete_value(root->right, right_min);
		}
	}

	return root;
}

int get_successor(struct bst_node *node, int value)
{
	if (node == NULL) return -1;

	struct bst_node *target = node;

	while (target->value != value) {
		if (value < target->value) {
			target = target->left;
		} else if (value > target->value) {
			target = target->right;
		}
	}

	// arrived at target node
	if (target->right != NULL) {
		// get min value of right subtree
		return get_min(target->right);
	} else {
		// get lowest ancestor that is a left child in the path to target value
		struct bst_node *successor = NULL;
		struct bst_node *ancestor = node;
		while (ancestor != NULL) {
			if (value < ancestor->value) {
				successor = ancestor;
				ancestor = ancestor->left;
			} else {
				ancestor = ancestor->right;
			}
		}

		return successor->value;
	}
}


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
