#ifndef LISTS_H
#define LISTS_H
#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: pointer to the next node
 *
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *insert_node(listint_t **head, int number);
size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);
#endif /* LISTS_H */