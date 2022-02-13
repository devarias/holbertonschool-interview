#include "lists.h"
/**
 * check_cycle - checks if a SLL has a cycle
 * @list: pointer to the head of the linked list
 * Return: 1 if there is a cycle, otherwise 0.
 **/
int check_cycle(listint_t *list)
{
	listint_t *second = list;
	listint_t *first = list;

	while (first && first->next)
	{
		second = second->next;
		first = first->next->next;
		if (second == first)
			return (1);
	}
	return (0);
}
