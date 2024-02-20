#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* TPMer - sorts and merges the sub arrays in source
* @start: starting index (inclusive) for the left sub array
* @middle: end index (exclusive) for the left sub array and
* starting index (inclusive) for the right sub array
* @end: end index (exclusive) for the right sub array
* @dest: destination for data
* @source: source of data
*
* Return: void
*/
void TPMer(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t i, var2, var4;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	i = start;
	var2 = middle;
	for (var4 = start; var4 < end; var4++)
	{
		if (i < middle && (var2 >= end || source[i] <= source[var2]))
		{
			dest[var4] = source[i];
			i++;
		}
		else
		{
			dest[var4] = source[var2];
			var2++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
* TPSplMer - recursively splits the array and merges the sorted arrays
* @start: starting index (inclusive)
* @end: end index (exclusive)
* @array: the array to sort
* @copy: a copy of the array
*
* Return: void
*/
void TPSplMer(size_t start, size_t end, int *array, int *copy)
{
	size_t midd;

	if (end - start < 2)
		return;
	midd = (start + end) / 2;
	TPSplMer(start, midd, array, copy);
	TPSplMer(midd, end, array, copy);
	TPMer(start, midd, end, array, copy);
	for (midd = start; midd < end; midd++)
		copy[midd] = array[midd];
}

/**
* merge_sort - sorts an array of integers in ascending order using the
* Merge sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *cpy;

	if (array == NULL || size < 2)
		return;
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		return;
	for (i = 0; i < size; i++)
		cpy[i] = array[i];
	TPSplMer(0, size, array, cpy);
	free(cpy);
}
