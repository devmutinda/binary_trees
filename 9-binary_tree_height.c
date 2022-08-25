#include "binary_trees.h"
/**
 * calc_height - calculates height
 * @ptr: pointer to root node
 * @h: pointer to height
 * Return: void
 */
void calc_height(const binary_tree_t *ptr, size_t *h)
{
	if (ptr)
	{
		if (ptr->left || ptr->right)
			(*h)++;
		calc_height(ptr->left, h);
	}
}
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
		return (0);

	calc_height(tree, &height);

	return (height);
}
