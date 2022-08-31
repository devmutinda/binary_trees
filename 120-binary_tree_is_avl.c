#include "binary_trees.h"
/**
 * get_height - calculates height of tree
 * @tree: binary tree
 * Return: height
 */
int get_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (-1);
	if (!tree->left && !tree->right)
		return (0);
	left = get_height(tree->left) + 1;
	right = get_height(tree->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}
/**
 * check_avl - check is tree is valid
 * @tree: avl tree
 * @n: value of root node
 * Return: 0 or 1
 */
int check_avl(const binary_tree_t *tree, int n)
{
	if (!tree->left && !tree->right)
		return (1);
	if (!tree->right || !tree->left)
	{
		if ((!tree->left && tree->n >= tree->right->n)
				|| (!tree->right && tree->n <= tree->left->n))
			return (0);
		else
			return (1);
	}
	else if ((tree->n <= tree->left->n) ||
			(tree->n >= tree->right->n))
	{
		return (0);
	}
	else if ((tree->n < n && (tree->left->n >= n || tree->right->n >= n))
			|| (tree->n > n && (tree->left->n <= n || tree->right->n <= n)))
		return (0);

	return (check_avl(tree->left, n) && check_avl(tree->right, n));
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left, right, status;

	if (!tree)
		return (0);
	left = get_height(tree->left);
	right = get_height(tree->right);

	if (left != right)
		return (0);

	status = check_avl(tree, tree->n);

	return (status);
}
