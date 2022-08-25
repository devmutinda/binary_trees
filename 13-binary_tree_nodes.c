#include "binary_trees.h"
/**
 * calc_nodes - calculates no. of nodes
 * @tree: the node
 * @nodes: pointer to nodes
 * Return: void
 */
void calc_nodes(const binary_tree_t *tree, size_t *nodes)
{
	if (tree)
	{
		if (tree->right || tree->left)
			(*nodes)++;

		calc_nodes(tree->left, nodes);
		calc_nodes(tree->right, nodes);
	}
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size or 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);

	calc_nodes(tree, &nodes);

	return (nodes);
}
