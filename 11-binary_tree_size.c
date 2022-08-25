#include "binary_trees.h"
/**
 * calc_size - calculates size
 * @node: the node
 * @size: pointer to size
 * Return: void
 */
void calc_size(const binary_tree_t *tree, size_t *size)
{
	if (tree)
	{
		calc_size(tree->left, size);
		calc_size(tree->right, size);
		(*size)++;
	}
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	calc_size(tree, &size);

	return (size);
}
