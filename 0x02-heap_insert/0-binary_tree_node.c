#include "binary_trees.h"
/**
 * binary_tree_node - Binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: value of n
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node;


    node = malloc(sizeof(binary_tree_t));
    if (node == NULL)
        return (NULL);

    node->n = value;
    node->left = NULL;
    node->right = NULL;

    if (parent == NULL)
    {   
        node->parent = NULL;
        return (node);
    }
    node->parent = parent;
    return (node);
}