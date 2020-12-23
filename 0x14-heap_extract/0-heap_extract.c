#include "binary_trees.h"

/**
* height - function that measures the height of a binary tree.
* @tree: node parent
* Return: the height
*/

size_t height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (!tree)
		return (0);

	h_left = tree->left ? 1 + height(tree->left) : 0;
	h_right = tree->right ? 1 + height(tree->right) : 0;

	return (h_left > h_right ? h_left : h_right);
}


/**
 * preorder - binary tree using pre-order traversal
 * @root: pointer root of the tree
 * @node: pointer node in the tree
 * @h: height of tree
 * @counter: counter on the tree
 **/
void preorder(heap_t *root, heap_t **node, size_t h, size_t counter)
{
	if (!root)
		return;

	if (h == counter)
		*node = root;

	counter++;

	if (root->left)
		preorder(root->left, node, h, counter);
	if (root->right)
		preorder(root->right, node, h, counter);
}

/**
 * sort - binary tree sort
 * @tmp: pointer to the heap root
 * Return: pointer to last node
 **/
heap_t *sort(heap_t *tmp)
{
	int value;

	while (tmp->left || tmp->right)
	{
		if (!tmp->right || tmp->left->n > tmp->right->n)
		{
			value = tmp->n;
			tmp->n = tmp->left->n;
			tmp->left->n = value;
			tmp = tmp->left;
		}
		else if (!tmp->left || tmp->left->n < tmp->right->n)
		{
			value = tmp->n;
			tmp->n = tmp->right->n;
			tmp->right->n = value;
			tmp = tmp->right;
		}
	}
	return (tmp);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	size_t h;
	heap_t *tmp, *preorder_node;

	if (!*root)
		return (0);

	tmp = *root;
	value = tmp->n;

	if (!tmp->left && !tmp->right)
	{
		*root = NULL;
		free(tmp);
		return (value);
	}

	h = height(tmp);
	preorder(tmp, &preorder_node, h, 0);
	tmp = sort(tmp);
	tmp->n = preorder_node->n;

	if (preorder_node->parent->right)
		preorder_node->parent->right = NULL;
	else
		preorder_node->parent->left = NULL;

	free(preorder_node);
	return (value);
}
