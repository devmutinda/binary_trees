#include "binary_trees.h"
/**
 * find_successor - finds successor of node
 * @node: node to be removed
 * Return: successor node
 */
bst_t *find_successor(bst_t *node)
{
	if (node->right)
	{
		if (node->right->left)
			return (node->right->left);
		else
			return (node->right);
	}
	if (node->left)
	{
		return (node->left);
	}
	return (NULL);

}
/**
 * process_success - processes deletion
 * @success: successor node
 * @tree: node to be removed
 * Return: void
 */
void process_success(bst_t *success, bst_t *tree)
{
	if (success == success->parent->left)
		success->parent->left = NULL;
	else if (success == success->parent->right)
		success->parent->right = NULL;

	success->parent = tree->parent;
	if (success->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = success;
		else
			tree->parent->right = success;
	}
	if (success != tree->left && tree->left)
	{
		tree->left->parent = success;
		success->left = tree->left;
	}
	else
		success->left = NULL;
	if (success != tree->right && tree->right)
	{
		tree->right->parent = success;
		success->right = tree->right;
	}
	else
		success->right = NULL;

}
/**
 * remover - removes node
 * @tree: pointer to tree
 * @value: value to be removed
 * Return: pointer to new root
 */
bst_t *remover(bst_t *tree, int value)
{
	bst_t *success = NULL;

	if (!tree)
		return (NULL);

	if (tree->n == value)
	{
		success = find_successor(tree);
		if (success)
			process_success(success, tree);
		else
		{
			success = tree;
			if (tree->parent->left == tree)
				tree->parent->left = NULL;
			else
				tree->parent->right = NULL;
		}

		free(tree);
		if (!success->parent)
			return (success);
		while (success->parent)
			success = success->parent;

		return (success);
	}

	if (tree->n > value)
		return (remover(tree->left, value));
	else
		return (remover(tree->right, value));
}
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to new root node of the tree after removing desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new;

	if (!root)
		return (NULL);

	new = remover(root, value);

	if (root != new)
		return (new);

	return (root);
}
