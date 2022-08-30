#include "binary_trees.h"
/**
 * check_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @status: the status
 * Return: int
 */
int check_complete(const binary_tree_t *tree, int *status)
{
	int left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);

	left = check_complete(tree->left, status) + 1;
	right = check_complete(tree->right, status) + 1;

	if (!tree->left && tree->right)
		*status = 0;
	else if (!tree->right && tree->parent->right->left &&
			tree == tree->parent->left)
		*status = 0;
	if (right > left)
	{
		*status = 0;
		return (right);
	}
	else
		return (left);

}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 0 or 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int status = 1, height;

	height = check_complete(tree, &status);
	if (!height)
		return (1);

	return (status);
}
