#include "binary_trees.h"

/**
 * get_tree_size - function doc
 * @root: first node
 * Return: size
 */
int get_tree_size(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + get_tree_size(root->left) + get_tree_size(root->right));
}

/**
 * swap - function doc
 * @node_a: a
 * @node_b: b
 * Return: first node
 */
heap_t *swap(heap_t *node_a, heap_t *node_b)
{
	node_a->n = node_a->n * node_b->n;
	node_b->n = node_a->n / node_b->n;
	node_a->n = node_a->n / node_b->n;

	return (node_a);
}

/**
 * get_node - function doc
 * @root: root
 * @size: size
 *
 * Return: ptr node
 */
heap_t *get_node(heap_t *root, int size)
{
	int b_idx, mask  = 0;

	for (; 1 << (b_idx + 1) <= size; b_idx++)
		;

	for (b_idx--; b_idx >= 0; b_idx--)
	{
		mask = 1 << b_idx;
		if (size & mask)
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}

/**
 * heapify - function doc
 * @root: root
 */
void heapify(heap_t *root)
{
	heap_t *max;
	int first = 0;

	if (!root)
		return;
	while (max || !first)
	{
		max = NULL;
		first = 1;
		if (root->left && root->left->n > root->n)
			max = root->left;
		if (root->right && root->right->n > root->n &&
				(max && root->right->n > max->n))
			max = root->right;
		if (max)
			root = swap(max, root);
	}
}

/**
 * heap_extract - function doc
 * @root: root
 * Return: a value
 */
int heap_extract(heap_t **root)
{
	int max;
	int size;
	heap_t *last_node;

	if (!root || !*root)
		return (0);
	max = (*root)->n;
	size = get_tree_size(*root);
	last_node = get_node(*root, size);

	if (last_node->parent)
	{
		swap(last_node, *root);
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	}
	else
	{
		*root = NULL;
	}
	free(last_node);
	heapify(*root);
	return (max);
}
