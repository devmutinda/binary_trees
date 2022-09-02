#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *tree;
    int array[] = {
	    98, 110, 43, 56, 2, 78, 123, 76, 234
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_avl(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);

    tree = avl_remove(tree, 2);
    printf("Removed 2...\n");
    binary_tree_print(tree);

    /*tree = avl_remove(tree, 110);
    printf("Removed 110...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 123);
    printf("Removed 123...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 34);
    printf("Removed 34...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 22);
    printf("Removed 22...\n");
    binary_tree_print(tree);*/
    binary_tree_delete(tree);
    return (0);
}
