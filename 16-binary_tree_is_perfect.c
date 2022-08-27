#include "binary_trees.h"
/**
 * binary_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height or 0
 */
int binary_height(const binary_tree_t *tree)
{
	int right, left;

	if (tree == NULL)
		return (-1);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left = binary_height(tree->left) + 1;
	right = binary_height(tree->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}

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
 * new_size - calculates size
 * @tree: the node
 * @size: pointer to size
 * Return: void
 */
void new_size(const binary_tree_t *tree, int *size)
{
	if (tree)
	{
		new_size(tree->left, size);
		new_size(tree->right, size);
		(*size)++;
	}
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if true, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int full = 1, left_h, right_h, bf, perfect, count_l = 0, count_r = 0;

	if (!tree)
		return (0);

	check_full(tree, &full);
	left_h = binary_height(tree->left);
	right_h = binary_height(tree->right);
	new_size(tree->left, &count_l);
	new_size(tree->right, &count_r);

	bf = left_h - right_h;
	if (count_l != count_r)
		perfect = 0;
	else if (full && !bf)
		perfect = 1;
	else
		perfect = 0;

	return (perfect);
}
