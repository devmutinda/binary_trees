#include "binary_trees.h"
/**
 * calc_leaves - calculates no. of leaves
 * @tree: the node
 * @leaves: pointer to size
 * Return: void
 */
void calc_leaves(const binary_tree_t *tree, size_t *leaves)
{
	if (tree)
	{
		if (!tree->left && !tree->right)
			(*leaves)++;
		calc_leaves(tree->left, leaves);
		calc_leaves(tree->right, leaves);
	}
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size or 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (0);

	calc_leaves(tree, &leaves);

	return (leaves);
}
