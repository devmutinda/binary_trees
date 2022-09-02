#include "binary_trees.h"
/**
 * swap_nodes - swaps two nodes
 * @max: the larger node
 * @min: the small node
 * Return: void
 */
heap_t *swap_nodes(heap_t *max, heap_t *min)
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

	return (max);
}
/**
 * get_nodes - calculates no of nodes
 * @root: pointer to root node
 * Return: no of nodes
 */
int get_nodes(const binary_tree_t *root)
{
	if (!root)
		return (0);
	return (get_nodes(root->left) +
			get_nodes(root->right) + 1);
}
/**
 * insert_heap - inserts node into heap
 * @node: pointer to node
 * @value: value to be inserted
 * @parent: parent to node
 * @new: pointer to new node
 * Return: root node
 */
heap_t *insert_heap(heap_t *node, int value, heap_t *parent, heap_t **new)
{
	int node_l, node_r;

	if (!node)
	{
		*new = binary_tree_node(parent, value);
		return (*new);
	}

	node_l = get_nodes(node->left);
	node_r = get_nodes(node->right);

	if (!(node_l % 2) || node_l == node_r)
		node->left = insert_heap(node->left, value, node, new);

	else
		node->right = insert_heap(node->right, value, node, new);

	if (node->right)
	{
		if (node->right->n > node->n)
			node = swap_nodes(node->right, node);
	}
	if (node->left)
	{
		if (node->left->n > node->n)
			node = swap_nodes(node->left, node);
	}

	return (node);
}
/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;

	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	*root = insert_heap(*root, value, new, &new);

	return (new);
}
