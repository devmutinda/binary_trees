#include "binary_trees.h"
/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent, *hold, *temp;

	if (!tree || !tree->right)
		return (NULL);

	parent = tree->right;
	hold = parent->left;
	temp = tree->parent;
	parent->left = tree;
	parent->parent = temp;
	tree->parent = parent;
	if (hold)
	{
		hold->parent = tree;
		tree->right = hold;
	}
	else
		tree->right = NULL;

	return (parent);
}
