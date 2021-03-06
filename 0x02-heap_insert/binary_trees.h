#ifndef _BINARY_H
#define _BINARY_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
int n;
struct binary_tree_s *parent;
struct binary_tree_s *left;
struct binary_tree_s *right;
};

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;

typedef struct binary_tree_s binary_tree_t;
void binary_tree_print(const binary_tree_t *);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
int tree_height(heap_t *tree);
int is_leaf(heap_t *node);
binary_tree_t *add_node(binary_tree_t *tree, int level, int value);
int tree_depth(const binary_tree_t *tree);

#endif /* _BINARY_H */
