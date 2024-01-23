#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                   using the Selection sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	size_t i, j, min_index;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			/* Swap array[i] and array[min_index] */
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			/* Print array after each swap */
			for (j = 0; j < size - 1; j++)
				printf("%d, ", array[j]);
			printf("%d\n", array[j]);
		}
	}
}
