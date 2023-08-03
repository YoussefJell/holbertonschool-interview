#include "binary_trees.h"
/**
 * binary_tree_height - returns binary tree height
 *
 * @tree: the tree
 * Return: int
 */
int binary_tree_height(const binary_tree_t *tree)
{

	int left_height;
	int right_height;

	if (tree == NULL)
	{
		return (-1);
	}
	else
	{
		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);
		return (1 + ((left_height > right_height) ? left_height : right_height));
	}
}
/**
 * is_bst - checks if tree is bst
 *
 * @tree: tree to chek
 * @min: int min
 * @max: int max
 * Return: int
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
	{
		return (1);
	}

	if (tree->n < min || tree->n > max)
	{
		return (0);
	}

	return (is_bst(tree->left, min, tree->n - 1) &&
			is_bst(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_is_avl - checks if a binary tree is avl
 *
 * @tree: tree to check
 * Return: int
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	int left_height;
	int right_height;

	if (tree == NULL)
	{
		return (0);
	}

	if (!is_bst(tree, INT_MIN, INT_MAX))
	{
		return (0);
	}

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (abs(left_height - right_height) > 1)
	{
		return (0);
	}

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
	{
		return (0);
	}

	return (1);
}
