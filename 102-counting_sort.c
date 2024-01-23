#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    int *count_arr = malloc(sizeof(int) * (max + 1));
    int *out_arr = malloc(sizeof(int) * size);

    if (!count_arr || !out_arr)
    {
        free(count_arr);
        free(out_arr);
        return;
    }

    for (int j = 0; j <= max; j++)
        count_arr[j] = 0;

    for (size_t k = 0; k < size; k++)
        count_arr[array[k]]++;

    print_array(count_arr, max + 1);

    for (int l = 1; l <= max; l++)
        count_arr[l] += count_arr[l - 1];

    for (size_t m = 0; m < size; m++)
    {
        out_arr[count_arr[array[m]] - 1] = array[m];
        count_arr[array[m]]--;
    }

    for (size_t n = 0; n < size; n++)
        array[n] = out_arr[n];

    free(count_arr);
    free(out_arr);
}

