#include "binary_trees.h"
/**
 * insert - inserts into BST
 * @tree: pointer to root of BST
 * @value: value to be inserted
 * @parent: parent of node
 * Return: pointer to created node
 */
avl_t *insert(avl_t *tree, int value, avl_t *parent)
{
	if (!tree)
	{
		return (binary_tree_node(parent, value));
	}
	if (tree->n > value)
	{
		parent = tree;
		return (insert(tree->left, value, parent));
	}
	else if (tree->n < value)
	{
		parent = tree;
		return (insert(tree->right, value, parent));
	}

	else
		return (NULL);
}
/**
 * balance_avl - balances the binary tree
 * @node: the node
 * Return: void
 */
void balance_avl(avl_t *node)
{
	int bf;

	if (node)
	{
	bf = binary_tree_balance(node);
	if (bf > 1)
	{
		binary_tree_rotate_right(node);
	}
	else if (bf < -1)
	{
		binary_tree_rotate_left(node);
	}

	balance_avl(node->left);
	balance_avl(node->right);
	}
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

	new = insert(*tree, value, new);
	if (new)
	{
	if (new->parent->n > new->n)
		new->parent->left = new;
	else
		new->parent->right = new;
	}

	balance_avl(*tree);

	return (new);
}
