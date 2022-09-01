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

	temp = tree->parent;
	if (!tree->left && tree->right->left)
	{
		parent = tree->right->left;
		hold = tree->right;
		hold->right = parent->right;
		hold->left = parent->left;
		tree->right = NULL;
		hold->parent = parent;
		parent->right = hold;
	}
	else
	{
		parent = tree->right;
		hold = parent->left;
		if (hold)
		{
			hold->parent = tree;
			tree->right = hold;
		}
		else
			tree->right = NULL;
	}
	parent->parent = temp;
	parent->left = tree;
	tree->parent = parent;
	if (temp)
	{
		if (tree == temp->left)
			temp->left = parent;
		else
			temp->right = parent;
	}

	return (parent);
}
