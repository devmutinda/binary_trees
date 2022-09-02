#include "binary_trees.h"
/**
 * insert_sorted - inserts into avl tree
 * @node: pointer to root node
 * @parent: pointer to parent
 * @array: sorted array
 * @l: left index
 * @r: right index
 * Return: pointer to root node
 */
avl_t *insert_sorted(avl_t *node, avl_t *parent, int *array, int l, int r)
{
	int mid;

	mid = (l + r) / 2;

	if (l > r)
		return (NULL);

	node = binary_tree_node(parent, array[mid]);
	if (!node)
		return (NULL);

	node->left = insert_sorted(node->left, node, array, l, mid - 1);
	node->right = insert_sorted(node->right, node, array, mid + 1, r);

	return (node);
}
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array)
		return (NULL);

	root = insert_sorted(root, root, array, 0, size - 1);

	return (root);
}
