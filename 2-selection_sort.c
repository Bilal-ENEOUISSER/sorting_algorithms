#include "sort.h"

/**
* selection_sort - sorts an array using selection sort
*
* @array: array to be sorted
* @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	unsigned int i, k;
	int min = 0, index = 0;

	for (i = 0; i < size; i += 1)
	{
		min = array[i];
		for (k = i; k < size; k += 1)
		{
			if (array[k] < min)
			{
				min = array[k];
				index = k;
			}
		}
		if (min != array[i])
		{
			array[index] = array[i];
			array[i] = min;
			print_array(array, size);
		}

	}
}
