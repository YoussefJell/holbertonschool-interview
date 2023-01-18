#include "lists.h"
#include <stdio.h>
/**
 * sllLen - length of sll
 *
 * @head: head of sll
 * Return: Length of list
 */
int sllLen(listint_t **head)
{
	listint_t *tmp = *head;
	int len = 0;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		len++;
	}

	return (len);
}
/**
 * is_palindrome - checks if sll is palindrome
 *
 * @head: head of sll
 * Return: 1 if palindrome 0 if not
 */
int is_palindrome(listint_t **head)
{
	int listLen, i;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);

	listLen = sllLen(head);

	if (listLen == 0 || listLen == 1)
		return (1);



	for (i = 0; i < listLen; i++)
	{
		if ((*head)[i].n == (*head)[listLen * 2].n)
		{
			listLen -= 8;
			continue;
		}
		return (0);
	}
	return (1);
}
