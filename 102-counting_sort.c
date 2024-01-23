#include "sort.h"

/**
 * counting_sort - Sorts an array using the Counting Sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *output_array, max_value, current_value, index;
    size_t i, k, m, n;

    if (size < 2)
        return;

    /* Find the maximum value in the array */
    max_value = array[0];
    for (i = 1; i < size; i++)
        if (array[i] > max_value)
            max_value = array[i];

    /* Allocate memory for the counting array and output array */
    count_array = malloc(sizeof(int) * (max_value + 1));
    output_array = malloc(sizeof(int) * size);

    /* Initialize the counting array with zeros */
    for (k = 0; k <= max_value; k++)
        count_array[k] = 0;

    /* Populate the counting array with frequency of each element */
    for (m = 0; m < size; m++)
    {
        current_value = array[m];
        count_array[current_value]++;
    }

    /* Print the counting array */
    print_array(count_array, max_value + 1);

    /* Modify the counting array to store cumulative frequencies */
    for (n = 1; n <= max_value; n++)
        count_array[n] += count_array[n - 1];

    /* Build the output array based on the counting array */
    for (i = 0; i < size; i++)
    {
        index = count_array[array[i]] - 1;
        output_array[index] = array[i];
        count_array[array[i]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    /* Free allocated memory */
    free(count_array);
    free(output_array);
}

