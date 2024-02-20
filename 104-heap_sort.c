#include "sort.h"

/**
 * sift_down - fixes a heap
 * @array: the heap to fix
 * @root: the root of the heap
 * @end: the last index of the heap
 * @size: size of the array
 *
 * Return: void
 */
void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t l_child, r_child, switch_int;
	int tp;

	while ((l_child = (2 * root) + 1) <= end)
	{
		switch_int = root;
		r_child = l_child + 1;
		if (array[switch_int] < array[l_child])
			switch_int = l_child;
		if (r_child <= end && array[switch_int] < array[r_child])
			switch_int = r_child;
		if (switch_int == root)
			return;
		tp = array[root];
		array[root] = array[switch_int];
		array[switch_int] = tp;
		print_array(array, size);
		root = switch_int;
	}
}

/**
 * m_hp - makes a heap from an unsorted array
 * @array: array to turn into a heap
 * @size: size of the array
 *
 * Return: void
 */
void m_hp(int *array, size_t size)
{
	size_t prt;

	for (prt = ((size - 1) - 1) / 2; 1; prt--)
	{
		sift_down(array, prt, size - 1, size);
		if (prt == 0)
			break;
	}
}

/**
 * heap_sort - sorts an array of ints in ascending order w/ the Heap sort algo
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t ed;
	int tp;

	if (array == NULL || size < 2)
		return;
	m_hp(array, size);
	ed = size - 1;
	while (ed > 0)
	{
		tp = array[ed];
		array[ed] = array[0];
		array[0] = tp;
		print_array(array, size);
		ed--;
		sift_down(array, 0, ed, size);
	}
}
