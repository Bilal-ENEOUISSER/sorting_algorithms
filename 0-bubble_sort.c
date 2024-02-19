#include "sort.h"

/**
 * switch_ints - switch two integers in an array.
 * @j: The first integer to swap.
 * @k: The second integer to swap.
 */
void switch_ints(int *j, int *k)
{
	int tp;

	tp = *j;
	*j = *k;
	*k = tp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t m, leng = size;
	bool baby = false;

	if (array == NULL || size < 2)
		return;

	while (baby == false)
	{
		baby = true;
		for (i = 0; m < leng - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				switch_ints(array + m, array + m + 1);
				print_array(array, size);
				baby = false;
			}
		}
		leng--;
	}
}
