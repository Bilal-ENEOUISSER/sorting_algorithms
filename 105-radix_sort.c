#include "sort.h"
#include <stdlib.h>

/**
* power_10 - calculates a positive power of 10
* @power: power of 10 to calculate
*
* Return: the corresponding power of 10
*/
unsigned int power_10(unsigned int power)
{
	unsigned int i, res;

	res = 1;
	for (i = 0; i < power; i++)
		res *= 10;
	return (res);
}

/**
* ct_st - sorts an array of integers in ascending order at a specific
* digit location using the Counting sort algorithm
* @array: array to sort
* @size: size of the array to sort
* @digit: digit to sort by
*
* Return: 1 if there is a need to keep sorting, 0 if not
*/
unsigned int ct_st(int *array, size_t size, unsigned int digit)
{
	int i, cot[10] = {0};
	int *cpy = NULL;
	size_t j, tp, ttl = 0;
	unsigned int d1, d2, srt = 0;

	d2 = power_10(digit - 1);
	d1 = d2 * 10;
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		exit(1);
	for (j = 0; j < size; j++)
	{
		cpy[j] = array[j];
		if (array[j] / d1 != 0)
			srt = 1;
	}
	for (i = 0; i < 10 ; i++)
		cot[i] = 0;
	for (j = 0; j < size; j++)
		cot[(array[j] % d1) / d2] += 1;
	for (i = 0; i < 10; i++)
	{
		tp = cot[i];
		cot[i] = ttl;
		ttl += tp;
	}
	for (j = 0; j < size; j++)
	{
		array[cot[(cpy[j] % d1) / d2]] = cpy[j];
		cot[(cpy[j] % d1) / d2] += 1;
	}
	free(cpy);
	return (srt);
}

/**
* radix_sort - sorts an array of integers in ascending order using
* the Radix sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void radix_sort(int *array, size_t size)
{
	unsigned int i, srt = 1;

	if (array == NULL || size < 2)
		return;
	for (i = 1; srt == 1; i++)
	{
		srt = ct_st(array, size, i);
		print_array(array, size);
	}
}
