#include "binary_trees.h"
/**
 * binary_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height or 0
 */
int binary_height(const binary_tree_t *tree)
{
	int right, left;

	if (!tree)
		return (0);

	left = binary_height(tree->left) + 1;
	right = binary_height(tree->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor(int)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h, right_h, bf;

	if (!tree)
		return (0);
	left_h = binary_height(tree->left);
	right_h = binary_height(tree->right);

	bf = left_h - right_h;
	return (bf);
}
