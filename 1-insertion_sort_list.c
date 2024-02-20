#include "sort.h"

void swap_list(listint_t *, listint_t *, listint_t **);

/**
* insertion_sort_list - sorts a list using insertion sort
*
* @list: double pointer to head of list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = NULL;
	listint_t *prv = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;
	prv = cur->prv;
	while (cur != NULL)
	{
		prv = cur->prv;
		while (prv != NULL && prv->n > cur->n)
		{
			swap_list(cur, prv, list);
			prv = cur->prv;
		}
		cur = cur->next;
	}
}

/**
* swap_list - swaps two members of a list
*
* @cur: current node
* @prv: previous node
* @head: head of list
*/
void swap_list(listint_t *cur, listint_t *prv, listint_t **head)
{
	listint_t *temp1 = cur->next;
	listint_t *temp2 = prv->prv;

	if (temp1 != NULL)
		temp1->prv = prv;
	if (temp2 != NULL)
		temp2->next = cur;
	cur->prv = temp2;
	prv->next = temp1;
	cur->next = prv;
	prv->prv = cur;
	if (*head == prv)
		*head = cur;
	print_list(*head);
}
