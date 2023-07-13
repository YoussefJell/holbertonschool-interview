#include "list.h"
/**
 * create_node - create a node in a linked list
 * @str: string
 * Return: pointer
 */
List *create_node(char *str)
{
	List *new = NULL;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * add_node_end - add node to end of linked list
 * @list: the list
 * @str: string
 * Return: pointer
 */
List *add_node_end(List **list, char *str)
{
	List *last, *new;

	new = create_node(str);
	if (!new)
		return (NULL);

	if (!*list)
	{
		*list = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last = (*list)->prev;
		last->next = new;
		(*list)->prev = new;
		new->prev = last;
		new->next = (*list);
	}
	return (new);
}

/**
 * add_node_begin - add node to beginning of linked list
 * @list: list
 * @str: string
 * Return: pointer
 */
List *add_node_begin(List **list, char *str)
{
	List *last, *new;

	new = create_node(str);
	if (!new)
		return (NULL);

	if (!*list)
	{
		*list = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last = (*list)->prev;
		last->next = new;
		(*list)->prev = new;
		new->prev = last;
		new->next = (*list);
		*list = new;
	}
	return (new);
}