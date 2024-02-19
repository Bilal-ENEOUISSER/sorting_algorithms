#include "sort.h"

void swap_list(listint_t *, listint_t *, listint_t **);

/**
* insertion_sort_list - sorts a list using insertion sort
*
* @list: double pointer to head of list
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
* @head: head of list
*/
void swap_list(listint_t *curr, listint_t *prev, listint_t **head)
{
	listint_t *temp1 = curr->next;
	listint_t *temp2 = prev->prev;

	if (temp1 != NULL)
		temp1->prev = prev;
	if (temp2 != NULL)
		temp2->next = curr;
	curr->prev = temp2;
	prev->next = temp1;
	curr->next = prev;
	prev->prev = curr;
	if (*head == prev)
		*head = curr;
	print_list(*head);
}
