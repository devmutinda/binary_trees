#include "binary_trees.h"
/**
 * balance_avl - balances the binary tree
 * @node: the node
 * @value: the value
 * Return: void
 */
avl_t *balance_avl(avl_t *node, int value)
{
	int bf;

	bf = binary_tree_balance(node);
	/*Left left case*/
	if (bf > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));

	/*Right right case*/
	else if (bf < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));

	/*Left right case*/
	else if (bf > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}

	/*Right left case*/
	else if (bf < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}
/**
 * insert - inserts into BST
 * @node: pointer to root of BST
 * @value: value to be inserted
 * @parent: parent of node
 * @new: newly created node
 * Return: pointer to created node
 */
avl_t *insert(avl_t *node, int value, avl_t *parent, avl_t **new)
{
	if (!node)
	{
		*new = binary_tree_node(parent, value);
		if ((*new)->parent->n > (*new)->n)
			(*new)->parent->left = *new;
		else
			(*new)->parent->right = *new;
		return (*new);
	}

	if (node->n > value)
		node->left = insert(node->left, value, node, new);

	else if (node->n < value)
		node->right = insert(node->right, value, node, new);

	else
		return (NULL);
	return (balance_avl(node, value));
}
/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to root node of AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (!(*tree))
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (*tree);
	}

	*tree = insert(*tree, value, new, &new);

	return (new);
}
