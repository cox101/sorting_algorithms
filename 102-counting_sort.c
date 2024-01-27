#include "sort.h"
#include <stdlib.h>

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

    /* Allocate memory for counting and output arrays */
    int *count_arr = malloc((max + 1) * sizeof(int));
    int *out_arr = malloc(size * sizeof(int));

    if (count_arr == NULL || out_arr == NULL)
    {
        free(count_arr);
        free(out_arr);
        return;
    }

    /* Initialize counting array to zero */
    for (int i = 0; i <= max; i++)
        count_arr[i] = 0;

    /* Populate the counting array */
    for (size_t k = 0; k < size; k++)
        count_arr[array[k]]++;

    /* Print the counting array */
    print_array(count_arr, max + 1);

    /* Update the original array with sorted values */
    for (size_t m = 0; m < size; m++)
    {
        out_arr[count_arr[array[m]] - 1] = array[m];
        count_arr[array[m]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (size_t n = 0; n < size; n++)
        array[n] = out_arr[n];

    /* Free allocated memory */
    free(count_arr);
    free(out_arr);
}

