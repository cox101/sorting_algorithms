#include "sort.h"
#include <stdio.h>

/* To swap two elements in an array */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, len = size;
    bool swapped = false;

    if (array == NULL || size < 2)
        return;

    do
    {
        swapped = false;
        for (i = 0; i < len - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap_ints(array + i, array + i + 1);
                print_array(array, size);
                swapped = true;
            }
        }
        len--;
    } while (swapped);
}
