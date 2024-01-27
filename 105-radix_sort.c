#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - Sorts an array using LSD Radix Sort algorithm
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum number to know the number of digits */
    int max = find_max(array, size);

    /* Do counting sort for every digit place */
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
        print_array(array, size);
    }
}

/**
 * counting_sort_radix - Performs counting sort on array for given digit place
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Current digit place (exponential value)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};

    if (output == NULL)
        return;

    /* Store count of occurrences in count[] */
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Change count[i] so that count[i] now contains the actual
       position of this digit in the output[] */
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the output array to array[] */
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * find_max - Finds the maximum number in an array
 * @array: Array of integers
 * @size: Size of the array
 * Return: Maximum number in the array
 */
int find_max(int *array, size_t size)
{
    int max = array[0];

    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}


