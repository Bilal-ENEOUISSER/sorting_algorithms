#include "sort.h"

void swap_list(listint_t *curr, listint_t *prev, listint_t **h);

/**
* cocktail_sort_list - Sorts a Doubly linked list with cocktail sort
* @list: A Doubly linked list
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *cur;
	listint_t *ma = NULL;
	listint_t *mi = NULL;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	cur = *list;
	do {
		while (cur->next)
		{
			if (cur->n > cur->next->n)
				swap_list(cur->next, cur, list);
			else
				cur = cur->next;
		}
		ma = cur;
		while (cur->prev != mi)
		{
			if (cur->n < cur->prev->n)
				swap_list(cur, cur->prev, list);
			else
				cur = cur->prev;
		}
		mi = cur;
	} while (mi != ma);
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
