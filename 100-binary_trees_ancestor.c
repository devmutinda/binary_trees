#include "binary_trees.h"
/**
 * check_ancestor - checks ancestor
 * @c: first node
 * @d: reference node
 * Return: pointer to common ancestor
 */
binary_tree_t *check_ancestor(const binary_tree_t *c, const binary_tree_t *d)
{
	if (!c)
		return (NULL);

	if (c->parent == d->parent)
	{
		return (c->parent);
	}
	else if (c->parent == d)
	{
		return ((binary_tree_t *)d);
	}
	else
		return (check_ancestor(c->parent, d));
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *parent = NULL;

	if (!first || !second)
		return (NULL);

	parent = check_ancestor(first, second);
	if (!parent)
		parent = check_ancestor(second, first);

	return (parent);
}
