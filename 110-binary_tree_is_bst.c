#include "binary_trees.h"
/**
 * check_bst - checks if it's BST
 * @tree: binary tree
 * Return: int
 */
int check_bst(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
	{
		return (1);
	}
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

	return (check_bst(tree->left) && check_bst(tree->right));
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int status;

	if (!tree)
		return (0);

	status = check_bst(tree);

	return (status);
}
