#include "binary_trees.h"
/**
 * insert - inserts into BST
 * @tree: pointer to root of BST
 * @value: value to be inserted
 * @parent: parent of node
 * Return: pointer to created node
 */
bst_t *insert(bst_t *tree, int value, bst_t *parent)
{
	if (!tree)
	{
		/*printf("parent is (%d), value is (%d)\n", parent->n, value);*/
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
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = NULL;

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
	/*binary_tree_print(*tree);*/
	}

	return (new);
}
