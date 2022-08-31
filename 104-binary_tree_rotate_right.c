#include "binary_trees.h"
/**
 * binary_tree_rotate_right -  performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parent, *hold, *temp;

	if (!tree || !tree->left)
		return (NULL);

	parent = tree->left;
	hold = parent->right;
	temp = tree->parent;
	parent->right = tree;
	parent->parent = temp;
	tree->parent = parent;
	if (temp)
	{
		if (tree == temp->left)
			temp->left = parent;
		else
			temp->right = parent;
	}
	if (hold)
	{
		hold->parent = tree;
		tree->left = hold;
	}
	else
		tree->left = NULL;

	return (parent);
}
