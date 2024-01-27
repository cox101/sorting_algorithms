#include "sort.h"

/**
 * quick_sort_hoare - sorts an array using the Quicksort algorithm (Hoare)
 * @array: array of integers to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (size < 2)
        return;

    quicksort_hoare(array, 0, (int)size - 1, size);
}

/**
 * quicksort_hoare - recursive helper function for Quicksort (Hoare)
 * @array: array to sort
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 */
void quicksort_hoare(int *array, int left, int right, size_t size)
{
    int pivot;

    if (left < right)
    {
        pivot = hoare_partition(array, left, right, size);
        quicksort_hoare(array, left, pivot, size);
        quicksort_hoare(array, pivot + 1, right, size);
    }
}

/**
 * hoare_partition - performs the Hoare partition scheme for Quicksort
 * @array: array to partition
 * @left: starting index of the partition
 * @right: ending index of the partition
 * @size: size of the array
 * Return: index of the pivot after partition
 */
int hoare_partition(int *array, int left, int right, size_t size)
{
    int tmp, pivot = array[right];
    int i = left - 1;
    int j = right + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
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
    return 0;
}

