#ifndef BINARY_H
#define BINARY_H

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

/* STRUCTS AND DEFINITIONS */
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

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s avl_t;

binary_tree_t *basic_tree(void);
int print_t(const binary_tree_t *tree, int offset, int depth, char **s);
size_t _height(const binary_tree_t *tree);
void binary_tree_print(const binary_tree_t *tree);
int binary_tree_height(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int min, int max);
int binary_tree_is_avl(const binary_tree_t *tree);

#endif
