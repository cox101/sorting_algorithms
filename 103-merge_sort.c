#include "sort.h"

/**
 * merge_sort - Sorts an array using the Merge Sort algorithm
 * @array: Array of integers to sort
 * @size: Size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *temp_array;


	if (!array || size < 2)
		return;

	temp_array = malloc(sizeof(int) * size);

	if (temp_array == NULL)
		return;

	merge_recursion(temp_array, array, 0, size);
	free(temp_array);
}

/**
 * merge_recursion - Recursive function that performs Merge Sort
 * @temp_array: Temporary array for merging
 * @array: Array to be sorted
 * @left: Index of the left element
 * @right: Index of the right element
 */

void merge_recursion(int *temp_array, int *array, size_t left, size_t right)
{
	size_t middle;


	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		merge_recursion(temp_array, array, left, middle);
		merge_recursion(temp_array, array, middle, right);
		merge_subarray(temp_array, array, left, middle, right);

	}
}

/**
 * merge_subarray - Merges subarrays during the Merge Sort
 * @temp_array: Temporary array for merging
 * @array: Array to be sorted
 * @left: Index of the left element
 * @middle: Index of the middle element
 * @right: Index of the right element
 */

void merge_subarray(int *temp_array, int *array, size_t left,
                    size_t middle, size_t right)
{
	size_t i, j, k = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (i = left, j = middle; i < middle && j < right; k++)
	{
		if (array[i] < array[j])
			temp_array[k] = array[i++];

		else
			temp_array[k] = array[j++];
	}

	while (i < middle)
		temp_array[k++] = array[i++];
	while (j < right)
		temp_array[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = temp_array[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
