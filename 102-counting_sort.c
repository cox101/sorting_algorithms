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
    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a counting array of size max + 1 and initialize it */
    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (int i = 0; i <= max; i++)
        count[i] = 0;

    /* Count occurrences of each element in the original array */
    for (size_t i = 0; i < size; i++)
        count[array[i]]++;

    /* Update count array to store the position of each element */
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Create a sorted array using the count array */
    int *sorted = malloc(size * sizeof(int));
    if (sorted == NULL)
    {
        free(count);
        return;
    }

    for (int i = size - 1; i >= 0; i--)
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
        printf("%d%s", count[i], (i == max) ? "\n" : ", ");

    free(count);
    free(sorted);
}

