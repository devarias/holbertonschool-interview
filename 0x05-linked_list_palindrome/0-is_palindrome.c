#include "lists.h"
/**
 * palindrome - checks if SLL is palindrome
 * @left: pointer to head of SLL
 * @right: head of SLL
 *
 * Return: 1 if it is palindrome, otherwise 0
 */

int palindrome(listint_t **left, listint_t *right)
{
	int equal;

	if (right == NULL)
		return (1);

	equal = palindrome(left, right->next);
	if (equal == 0)
		return (0);

	equal = (right->n == (*left)->n);

	*left = (*left)->next;

	return (equal);
}
/**
 * is_palindrome - checks if singly linked list is palindrome
 * @head: pointer to head of singly linked list
 *
 * Return: 1 if it is palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	if (!head)
		return (0);
	return (palindrome(head, *head));
}
