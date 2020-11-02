#include "binary_trees.h"

/**
* add_node - create a new node.
* @root: The node parent.
* @mid: number to add.
* Return: the new node.
*/

avl_t *add_node(avl_t **root, int mid)
{
	avl_t *new;

	new = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);

	new->n = mid;
	new->parent = *root;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

/**
* sorted_array - builds an AVL tree from an array recursively.
* @root: the principal node.
* @array: The array to be printed
* @start: start of array
* @end: end of array.
* Return: the AVL tree balanced
*/

avl_t *sorted_array(avl_t **root, int *array, int start, int end)
{
	avl_t *new;
	int mid = 0;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	new = add_node(root, array[mid]);

	if (mid != start)
		new->left = sorted_array(&new, array, start, mid - 1);

	if (mid != end)
		new->right = sorted_array(&new, array, mid + 1, end);

	return (new);
}

/**
* sorted_array_to_avl - builds an AVL tree from an array.
* @array: The array to be printed
* @size: Size of the array
* Return: the pointer root of the AVL tree completed.
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array)
		return (NULL);

	root = NULL;
	root = sorted_array(&root, array, 0, size - 1);

	return (root);
}
