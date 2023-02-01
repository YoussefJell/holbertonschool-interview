#include "lists.h"
/**
 * check_cycle - checks if sll has cycle
 *
 * @list: list to check
 * Return: 1 if cycle 0 if not
 */
int check_cycle(listint_t *list)
{
	listint_t *ptr1;
	listint_t *ptr2;

	if (list == NULL || list->next == NULL)
		return (0);

	ptr1 = list;
	ptr2 = list;

	while (ptr2 != NULL)
	{
		ptr2 = ptr2->next->next;
		ptr1 = ptr1->next;
		if (ptr2 == ptr1)
			return (1);
	}
	return (0);
}