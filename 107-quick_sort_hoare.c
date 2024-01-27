#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array using the Quick sort algorithm (Hoare partition scheme).
 * @array: Array of integers to sort.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort (Hoare partition scheme).
 * @array: Array to sort.
 * @left: Index of the left element.
 * @right: Index of the right element.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, int left, int right, size_t size)
{
	int pivot_index;

	if (left < right)
	{
		pivot_index = partition(array, left, right, size);
		quick_sort_recursive(array, left, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index, right, size);
	}
}

/**
 * partition - Finds the pivot index for Quick sort (Hoare partition scheme).
 * @array: Array to find the pivot in.
 * @left: Index of the left element.
 * @right: Index of the right element.
 * @size: Size of the array.
 *
 * Return: The index of the pivot element.
 */
int partition(int *array, int left, int right, size_t size)
{
	int tmp, pivot = array[right];
	size_t i, j;

	i = left - 1;
	j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return i;

		if (i != j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}

	/* The return statement above ensures this line is unreachable. */
	return 0;
}

