#include "binary_trees.h"
/**
 * get_height - calculates height of tree
 * @node: pointer to node in tree
 * Return: height of tree
 */
int get_height(heap_t *node)
{
	int left, right;

	if (!node)
		return (-1);

	left = get_height(node->left) + 1;
	right = get_height(node->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}

/**
 * get_new_node - gets the last node of heap
 * @node: the pointer to node
 * @lim: the height of tree
 * @new: stores last pointer
 * Return: void
 */
void get_new_node(heap_t *node, int lim, heap_t **new)
{
	if (node)
	{
		if (!lim)
			*new = node;

		else
		{
			get_new_node(node->left, lim - 1, new);
			get_new_node(node->right, lim - 1, new);
		}
	}
}
/**
 * swap_the_nodes - swaps two nodes
 * @max: the larger node
 * @min: the small node
 * Return: void
 */
heap_t *swap_the_nodes(heap_t *max, heap_t *min)
{
	heap_t *left, *right, *parent;

	parent = min->parent;
	max->parent = parent;
	if (parent)
	{
	if (parent->left == min)
		parent->left = max;
	else
		parent->right = max;
	}

	min->parent = max;
	left = max->left;
	right = max->right;
	if (min->left == max)
	{
		max->left = min;
		max->right = min->right;
		if (min->right)
			min->right->parent = max;
	}
	else
	{
		max->right = min;
		max->left = min->left;
		if (min->left)
			min->left->parent = max;
	}

	min->left = left;
	if (left)
		left->parent = min;
	min->right = right;
	if (right)
		right->parent = min;

	return (min->parent);
}
/**
 * swap_elements - initiates swapping of nodes in tree
 * @node: pointer to node
 * Return: new balanced node
 */
heap_t *swap_elements(heap_t *node)
{
	if (!node)
		return (NULL);
	if (node->left && node->right)
	{
		if (node->n < node->left->n || node->n < node->right->n)
		{
			if (node->left->n > node->right->n)
				node = swap_the_nodes(node->left, node);
			else
				node = swap_the_nodes(node->right, node);
		}
	}
	else if (node->left)
	{
		if (node->left->n > node->n)
			node = swap_the_nodes(node->left, node);
	}
	node->left = swap_elements(node->left);
	node->right = swap_elements(node->right);

	return (node);
}
/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of heap
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int value, height;
	heap_t *new;

	if (!(*root))
		return (0);

	value = (*root)->n;
	height = get_height(*root);
	get_new_node(*root, height, &new);
	new->left = (*root)->left;
	new->right = (*root)->right;

	if (new->parent->left == new)
		new->parent->left = NULL;
	else
		new->parent->right = NULL;
	new->parent = NULL;
	new->left->parent = new;
	new->right->parent = new;
	free(*root);
	new = swap_elements(new);

	*root = new;

	return (value);
}
