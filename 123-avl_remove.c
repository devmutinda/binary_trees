#include "binary_trees.h"
/**
 * find_successor - finds successor of node
 * @node: node to be removed
 * Return: successor node
 */
avl_t *find_successor(bst_t *node)
{
	avl_t *new;

	if (node->right)
	{
		new = node->right;
		if (!new->left)
			return (node->right);
		while (new->left)
			new = new->left;
		return (new);
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
void process_success(avl_t *success, avl_t *tree)
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
	if (success != tree->right && tree->right)
	{
		tree->right->parent = success;
		success->right = tree->right;
	}
}
/**
 * balance_tree - balances the binary tree
 * @node: the node
 * Return: void
 */
void balance_tree(avl_t *node)
{
	int bf;

	if (node)
	{
	bf = binary_tree_balance(node);
	/*Left left case*/
	if (bf > 1 && binary_tree_balance(node->left) >= 0)
		binary_tree_rotate_right(node);

	/*Right right case*/
	else if (bf < -1 && binary_tree_balance(node->right) <= 0)
		binary_tree_rotate_left(node);

	/*Left right case*/
	else if (bf > 1 && binary_tree_balance(node->left) < 0)
	{
		binary_tree_rotate_left(node->left);
		binary_tree_rotate_right(node);
	}

	/*Right left case*/
	else if (bf < -1 && binary_tree_balance(node->right) > 0)
	{
		binary_tree_rotate_right(node->right);
		binary_tree_rotate_left(node);
	}
	balance_tree(node->left);
	balance_tree(node->right);

	}
}
/**
 * remover - removes node
 * @tree: pointer to tree
 * @value: value to be removed
 * @success: the inorder successor
 * Return: pointer to new root
 */
avl_t *remover(avl_t *tree, int value, avl_t **success)
{
	if (!tree)
		return (NULL);

	if (tree->n == value)
	{
		if (tree->right || tree->left)
		{
			*success = find_successor(tree);
			process_success(*success, tree);
		}
		else
		{
			if (tree->parent->left == tree)
				tree->parent->left = NULL;
			else
				tree->parent->right = NULL;
		}

		free(tree);
		return (*success);
	}

	if (tree->n > value)
		tree->left = remover(tree->left, value, success);
	else if (tree->n < value)
		tree->right = remover(tree->right, value, success);
	else
		return (NULL);

	return (tree);
}
/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: pointer to new root node of tree after removing the desired value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new, *success = NULL;

	if (!root)
		return (NULL);

	new = remover(root, value, &success);
	balance_tree(new);

	return (new);
}
