#include "binary_trees.h"
/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		if (ptr->left)
			binary_tree_delete(ptr->left);
		if (ptr->right)
			binary_tree_delete(ptr->right);
		free(tree);
	}
}
