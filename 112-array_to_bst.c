#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL, *new;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		new = bst_insert(&root, array[i]);
		if (!new)
			continue;
	}

	return (root);
}
