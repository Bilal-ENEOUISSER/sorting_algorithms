#include "sort.h"

/**
* selection_sort - sorts an array using selection sort
*
* @array: array to be sorted
* @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	unsigned int var1, var2;
	int mi = 0, idx = 0;

	for (var1 = 0; var1 < size; var1 += 1)
	{
		mi = array[var1];
		for (var2 = var1; var2 < size; var2 += 1)
		{
			if (array[var2] < mi)
			{
				mi = array[var2];
				idx = var2;
			}
		}
		if (mi != array[var1])
		{
			array[idx] = array[var1];
			array[var1] = mi;
			print_array(array, size);
		}

	}
}
