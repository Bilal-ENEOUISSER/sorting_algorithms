#include "sort.h"

void ins_sort(int *, long int, long int, size_t);

/**
* shell_sort - sorts using shell sort and knuths sequence
*
* @array: array to sort
* @size: size of array
*/
void shell_sort(int *array, size_t size)
{
	long int var4 = 1;
	long int i, var5, tp;

	if (size < 2)
		return;

	while (var4 < (long int)size / 3)
		var4 = var4 * 3 + 1;

	while (var4 > 0)
	{
		for (i = var4; i < (long int) size; i++)
		{
			tp = array[i];
			for (var5 = i; var5 >= var4 && array[var5 - var4] > tp; var5 = var5 - var4)
				array[var5] = array[var5 - var4];
			array[var5] = tp;
		}
		print_array(array, size);
		var4 = (var4 - 1) / 3;
	}
}
