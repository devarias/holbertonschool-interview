#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - function
 *
 * @list: param
 * @str: param
 * Return: return
 */
List *add_node_end(List **list, char *str)
{
	List *new;
	char *str;

	if (!list)
		return (NULL);
	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	str = strdup(str);
	if (!str)
	{
		free(new);
		return (NULL);
	}
	new->str = str;
	if (!*list)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}
	new->next = *list;
	new->prev = (*list)->prev;
	(*list)->prev = new;
	new->prev->next = new;
	return (new);
}
/**
 * add_node_begin - Adds a new node to the beginning of a
 * double circular linked list
 *
 * @list:the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;
	char *str;

	if (!list)
		return (NULL);
	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	str = strdup(str);
	if (!str)
	{
		free(new);
		return (NULL);
	}
	new->str = str;
	if (*list)
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev = new;
		if (new->prev)
			new->prev->next = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
	}
	*list = new;
	return (new);
}
