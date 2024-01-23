#include "sort.h"

void swap(int *x, int *y);

void quicksort_recursion(int array[], int low, int high);

int partition(int array[], int low, int high);

/**
 * swap - swaps two elements of an array to facilitate sorting
 * @x: pointer to an element of the array
 * @y: pointer to an element of the array
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * quicksort - Initializes the quicksort_recursion function
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 */
void quicksort(int *array, size_t size)
{
	quicksort_recursion(array, 0, length - 1);
}

/**
 * quicksort_recursion - recursively sorts the array
 * @array: An array to be sorted
 * @low: The index of the first element of the array to be sorted
 * @high: The index of the last element of the array to be sorted
 */
void quicksort_recursion(int array[], int low, int high)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high);

		quicksort_recursion(array, low, pivot_index - 1);
		quicksort_recursion(array, pivot_index + 1, high);
	}
}

/**
 * partition - Carries out the step of partitioning the array for sorting.
 * @array: An array
 * @low: The lower index of the array to be partitioned
 * @high: The highest index of the array to be partitioned
 * Return: The pivotal index
 */
int partition(int array[], int low, int high)
{
	int pivot_value = array[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);

	return (i);
}
