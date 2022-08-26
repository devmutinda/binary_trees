#include "binary_trees.h"
/**
 * check_full - checks if full
 * @tree: binary tree
 * @f: pointer to full
 * Return: void
 */
void check_full(const binary_tree_t *tree, int *f)
{
	if (tree)
	{
		if ((!tree->left && tree->right) || (tree->left && !tree->right))
			*f = 0;

		check_full(tree->left, f);
		check_full(tree->right, f);
	}
}
/**
 * binary_tree_is_full - binary_tree_is_full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 1;

	if (!tree)
		return (0);

	check_full(tree, &full);

	return (full);
}
