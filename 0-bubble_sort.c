#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, m, new_m;
	int switch_int;

	if (array == NULL || size < 2)
		return;

	m = size;
	while (m > 0)
	{
		new_m = 0;
		for (i = 0; i < m - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				switch_int = array[i];
				array[i] = array[i + 1];
				array[i + 1] = switch_int;
				new_m = i + 1;
				print_array(array, size);
			}
		}
		m = new_m;
	}
}
