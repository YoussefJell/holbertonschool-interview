#include "lists.h"
/**
 * find_listint_loop - finds a loop
 *
 * @head: head of loop
 * Return: Pointer to node
 */
listint_t *find_listint_loop(listint_t *head)
{

	listint_t *slow;
	listint_t *fast;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow = head->next;
	fast = head->next->next;

	while (fast != NULL && fast->next != NULL)
	{
		if (slow == fast)
			break;

		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
		return (NULL);

	slow = head;

	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);
}
