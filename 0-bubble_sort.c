#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array in ascending order using the Bubble Sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int tmp;

    if (size < 2 || array == NULL)
        return;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                /* Swap the elements */
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;

                /* Print the current state of the array */
                print_array(array, size);
            }
        }
    }
}

