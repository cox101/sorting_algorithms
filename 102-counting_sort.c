#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output;
    size_t i, max = 0;

    if (size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
    {
        if ((size_t)array[i] > max)
            max = array[i];
    }

    /* Create counting array and initialize to 0 */
    count = malloc((max + 1) * sizeof(int));
    if (!count)
        return;

    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Count occurrences of each element in the array */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Print the counting array */
    print_array(count, max + 1);

    /* Update counting array to store the position of each element in the sorted array */
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Allocate memory for the output array */
    output = malloc(size * sizeof(int));
    if (!output)
    {
        free(count);
        return;
    }

    /* Build the output array using the counting array */
    for (i = size - 1; i < size; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted array back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Print the sorted array */
    print_array(array, size);

    /* Free allocated memory */
    free(count);
    free(output);
}

