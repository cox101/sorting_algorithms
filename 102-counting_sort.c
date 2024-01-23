#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a counting array and initialize it with zeros */
    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (int i = 0; i <= max; i++)
        count[i] = 0;

    /* Count the occurrences of each element in the original array */
    for (size_t i = 0; i < size; i++)
        count[array[i]]++;

    /* Update the counting array to store the cumulative count of elements */
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Create a sorted array based on the counting array */
    int *sorted = malloc(size * sizeof(int));
    if (sorted == NULL)
    {
        free(count);
        return;
    }

    for (ssize_t i = size - 1; i >= 0; i--)
    {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted array back to the original array */
    for (size_t i = 0; i < size; i++)
        array[i] = sorted[i];

    /* Print the counting array */
    printf("Array after counting: ");
    for (int i = 0; i <= max; i++)
        printf("%d%s", count[i], i == max ? "\n" : ", ");

    /* Free dynamically allocated memory */
    free(count);
    free(sorted);
}

