#include "lists.h"
#include <stdlib.h>

/**
 * insert_node -  inserts a number into a sorted singly linked list.
 * @head: double pointer with the head
 * @number: integer to be added into the list
 *
 * Return: the new head
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL, *tmp = NULL;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	new_node->n = number, new_node->next = NULL;

	if (!(*head))
	{
		new_node->n = number;
		*head = new_node;
		return (new_node);
	}

	tmp = *head;
	if (number <= tmp->n)
	{
		new_node->n = number;
		new_node->next = tmp;
		*head = new_node;
		return (new_node);
	}
	while (tmp->next)
	{
		if (tmp->next->n >= number)
			break;
		tmp = tmp->next;
	}
	new_node->n = number, new_node->next = tmp->next, tmp->next = new_node;
	return (new_node);
	if (!(tmp->next))
	{
		new_node->n = number;
		tmp->next = new_node;
		return (new_node);
	}
}