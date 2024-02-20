#include "sort.h"
#include "stdlib.h"

/**
* counting_sort - sorts an array of integers in ascending order using the
* Counting sort algorithm
* @array: array to sort
* @size: size of the array to sort
*
* Return: void
*/
void counting_sort(int *array, size_t size)
{
	int i, ma;
	int *ct = NULL, *cpy = NULL;
	size_t j, tp, ttl = 0;


	if (array == NULL || size < 2)
		return;
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		return;
	for (j = 0, ma = 0; j < size; j++)
	{
		cpy[j] = array[j];
		if (array[j] > ma)
			ma = array[j];
	}
	ct = malloc(sizeof(int) * (ma + 1));
	if (ct == NULL)
	{
		free(cpy);
		return;
	}
	for (i = 0; i <= ma; i++)
		ct[i] = 0;
	for (j = 0; j < size; j++)
		ct[array[j]] += 1;
	for (i = 0; i <= ma; i++)
	{
		tp = ct[i];
		ct[i] = ttl;
		ttl += tp;
	}
	for (j = 0; j < size; j++)
	{
		array[ct[cpy[j]]] = cpy[j];
		ct[cpy[j]] += 1;
	}
	print_array(ct, ma + 1);
	free(ct);
	free(cpy);
}
