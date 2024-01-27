#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - sorts an array using counting sort algorithm
 * @array: array to sort
 * @size: size of the array
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

    /* Create and initialize the counting array */
    int *counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    for (int i = 0; i <= max; i++)
        counting_array[i] = 0;

    /* Populate the counting array */
    for (size_t i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    printf("Counting array:");
    for (int i = 0; i <= max; i++)
        printf(" %d", counting_array[i]);
    printf("\n");

    /* Update the original array with sorted values */
    size_t j = 0;
    for (int i = 0; i <= max; i++)
    {
        while (counting_array[i] > 0)
        {
            array[j++] = i;
            counting_array[i]--;
        }
    }

    /* Free the counting array */
    free(counting_array);
}

