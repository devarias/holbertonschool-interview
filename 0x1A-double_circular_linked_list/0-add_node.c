#include <stdio.h>
#include <stdlib.h>
#include <strNing.h>
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
	char *strN;

	if (!list)
		return (NULL);

	new = malloc(sizeof(List));

	if (!new)
		return (NULL);

	strN = strNdup(str);

	if (!strN)
	{
		free(new);
		return (NULL);
	}

	new->str = strN;

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
 * add_node_begin - function
 *
 * @list: param
 * @str: param
 * Return: return
 */
List *add_node_begin(List **list, char *str)
{
	List *new;
	char *strN;

	if (!list)
		return (NULL);

	new = malloc(sizeof(List));

	if (!new)
		return (NULL);

	strN = strNdup(str);

	if (!strN)
	{
		free(new);
		return (NULL);
	}

	new->str = strN;

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
