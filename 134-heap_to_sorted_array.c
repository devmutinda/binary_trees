#include "binary_trees.h"
/**
 * get_number_nodes - calculates no of nodes
 * @root: pointer to root node
 * Return: no of nodes
 */
int get_number_nodes(const binary_tree_t *root)
{
	if (!root)
		return (0);
	return (get_number_nodes(root->left) +
			get_number_nodes(root->right) + 1);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to sorted array
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array, i, nodes;

	if (!heap)
		return (NULL);

	nodes = get_number_nodes(heap);
	array = malloc(sizeof(int) * nodes);

	for (i = 0; heap; i++)
	{
		array[i] = heap_extract(&heap);
	}
	*size = nodes;

	return (array);
}
