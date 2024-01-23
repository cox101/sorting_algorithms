#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - sorts an array using the Counting Sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    int *count_array, *output_array, max;

    /* Find the maximum value in the array */
    max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Allocate memory for counting and output arrays */
    count_array = malloc((max + 1) * sizeof(int));
    output_array = malloc(size * sizeof(int));

    /* Initialize counting array to zero */
    for (int j = 0; j <= max; j++)
        count_array[j] = 0;

    /* Count occurrences of each element in the array */
    for (size_t k = 0; k < size; k++)
        count_array[array[k]]++;

    /* Print the counting array */
    print_array(count_array, max + 1);

    /* Modify counting array to represent positions in the output array */
    for (int l = 1; l <= max; l++)
        count_array[l] += count_array[l - 1];

    /* Build the sorted output array */
    for (size_t m = 0; m < size; m++)
    {
        output_array[count_array[array[m]] - 1] = array[m];
        count_array[array[m]]--;
    }

    /* Copy the sorted output array back to the original array */
    for (size_t n = 0; n < size; n++)
        array[n] = output_array[n];

    /* Free allocated memory */
    free(count_array);
    free(output_array);
}

