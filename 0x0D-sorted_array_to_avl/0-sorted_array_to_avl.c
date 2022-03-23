#include "binary_trees.h"

/**
 * sorted_array_to_avl - function
 * @array: array
 * @size: size
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (!array ? NULL : insert_AVL_node(NULL, array, 0, (int)size - 1));
}

/**
 * insert_AVL_node - function
 * @parent: pointer to the parent
 * @array: array
 * @start: start index
 * @end: end index
 * Return: pointer to the created node
 */
avl_t *insert_AVL_node(avl_t *parent, int *array, int start, int end)
{
	size_t mid;
	avl_t *root = NULL;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	root = new_node(parent, array[mid]);
	if (!root)
		return (NULL);
	root->left = insert_AVL_node(root, array, start, mid - 1);
	root->right = insert_AVL_node(root, array, mid + 1, end);
	return (root);
}

/**
 * new_node - function
 * @parent: pointer to the parent
 * @value: value
 * Return: pointer to the created node
 */
avl_t *new_node(avl_t *parent, size_t value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
