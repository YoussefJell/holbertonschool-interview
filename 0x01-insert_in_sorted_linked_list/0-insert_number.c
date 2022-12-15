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
    tmp = *head;

    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if ((*head)->n >= new->n || *head == NULL || (*head)->next == NULL)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    while (tmp->next && tmp->next->n < new->n)
    {
        tmp = tmp->next;
    }
    new->next = tmp->next;
    tmp->next = new;
    return (new);
}