#include "sort.h"

/**
 * quick_sort_hoare - sorts an array using the Quicksort algorithm with Hoare partition
 * @array: array of integers to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}

/**
 * quick_sort_recursive - recursive helper function for Quicksort (Hoare partition)
 * @array: array to sort
 * @left: index of the leftmost element
 * @right: index of the rightmost element
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int left, int right, size_t size)
{
	int pivot_index;

	if (left < right)
	{
		pivot_index = hoare_partition(array, left, right, size);
		quick_sort_recursive(array, left, pivot_index, size);
		quick_sort_recursive(array, pivot_index + 1, right, size);
	}
}

/**
 * hoare_partition - performs the Hoare partition scheme for Quicksort
 * @array: array to partition
 * @left: index of the leftmost element
 * @right: index of the rightmost element
 * @size: size of the array
 * Return: index of the pivot after partition
 */
int hoare_partition(int *array, int left, int right, size_t size)
{
	int tmp, pivot = array[right];
	size_t i = (size_t)left - 1, j = (size_t)right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		if (i != j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
}
