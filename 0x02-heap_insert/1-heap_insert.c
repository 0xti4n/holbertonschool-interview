#include "binary_trees.h"

/**
* count - function that measures the size.
* @tree: node parent
* Return: size of tree - 1
*/

size_t count(const binary_tree_t *tree)
{
	size_t l_node, r_node;

	l_node = tree->left ? 1 + count(tree->left) : 0;
	r_node = tree->right ? 1 + count(tree->right) : 0;

	return (l_node + r_node);
}

/**
* binary_tree_size - function that measures size of a binary tree.
* @tree: node parent
* Return: size of binary tree
*/

size_t binary_tree_size(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	return (count(tree) + 1);
}

/**
 * is_perfect_binary_tree - check if the tree is perfect.
 * @count: number of nodes.
 * Return: 1 if is perfect, otherwise 0.
 */

int is_perfect_binary_tree(int count)
{
	while (count % 3 == 0)
		count = count / 3;

	if (count == 1)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_insert - insert binary tree node in level order
 * @tree: parent node
 * @new: node to insert
 * Return: new node.
 */

heap_t *binary_tree_insert(heap_t *tree, heap_t *new)
{
	size_t r_count, l_count;

	r_count = binary_tree_size(tree->right);
	l_count = binary_tree_size(tree->left);
	if (r_count == 0 && l_count == 0)
	{
		tree->left = new;
		new->parent = tree;
		return (tree);
	}

	else if (r_count == l_count)
		tree->left = binary_tree_insert(tree->left, new);

	else if (r_count == 0 && l_count == 1)
	{
		tree->right = new;
		new->parent = tree;
		return (tree);
	}

	else if (r_count < l_count)
	{
		if (is_perfect_binary_tree(l_count))
			tree->right = binary_tree_insert(tree->right, new);
		else
			tree->left = binary_tree_insert(tree->left, new);
	}
	return (tree);
}

/**
* heap_insert - Insert the node to a binary heap.
*
* @root: Pointer to the parent node.
* @value: Integer value in the new node.
* Return: The inserted node.
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;
	int swap;

	new = binary_tree_node(NULL, value);

	if (!*root)
	{
		*root = new;
		return (new);
	}

	*root = binary_tree_insert(*root, new);

	while (new->parent && new->n > new->parent->n)
	{
		swap = new->parent->n;
		new->parent->n = new->n;
		new->n = swap;
		new = new->parent;
	}
	return (new);
}
