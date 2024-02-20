#include "sort.h"

void swap_list(listint_t *, listint_t *, listint_t **);

/**
 * insertion_sort_list - sorts a list using insertion sort
 *
 * @list: double pointer to h of lis
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;
	listint_t *prev = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	prev = curr->prev;
	while (curr != NULL)
	{
		prev = curr->prev;
		while (prev != NULL && prev->n > curr->n)
		{
			swap_list(curr, prev, list);
			prev = curr->prev;
		}
		curr = curr->next;
	}
}

/**
 * swap_list - swaps two members of a list
 *
 * @curr: current node
 * @prev: previous node
 * @h: h of list
 */
void swap_list(listint_t *curr, listint_t *prev, listint_t **h)
{
	listint_t *tp1 = curr->next;
	listint_t *tp2 = prev->prev;

	if (tp1 != NULL)
		tp1->prev = prev;
	if (tp2 != NULL)
		tp2->next = curr;
	curr->prev = tp2;
	prev->next = tp1;
	curr->next = prev;
	prev->prev = curr;
	if (*h == prev)
		*h = curr;
	print_list(*h);
}
