#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * main - check the code for Holberton School students.
 * @number: number
 * @head: head of list
 * Return: Always 0.
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *tmp;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    if (*head == NULL)
        return (NULL);

    tmp = *head;

    new->n = number;
    new->next = NULL;

    while ((tmp != NULL) && (new->n > tmp->next->n))
        tmp = tmp->next;

    if (tmp == *head)
    {
        new->next = tmp->next;
        return (new);
    }

    if (tmp)
    {
        if (tmp->next != NULL)
            new->next = tmp->next;
        tmp->next = new;
        return (new);
    }
    return (NULL);
}