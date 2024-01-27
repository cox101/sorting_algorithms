#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array using Counting Sort algorithm
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

    /* Create counting array and initialize to 0 */
    int *count_array = malloc((max + 1) * sizeof(int));
    if (count_array == NULL)
        return;

    for (int i = 0; i <= max; i++)
        count_array[i] = 0;

    /* Populate the counting array */
    for (size_t i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Print the counting array */
    printf("Counting array:");
    for (int i = 0; i <= max; i++)
        printf(" %d", count_array[i]);
    printf("\n");

    /* Update the original array with sorted values */
    size_t j = 0;
    for (int i = 0; i <= max; i++)
    {
        while (count_array[i] > 0)
        {
            array[j++] = i;
            count_array[i]--;
        }
    }

    /* Free the counting array */
    free(count_array);
}

