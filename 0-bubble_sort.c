#include "sort.h"
#include <stdio.h>

/* To swap two elements in an array */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bubble_sort - sorts an array in ascending order
 * @array: array of ints to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size) {
    if (array == NULL || size <= 1)
        return;

    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}
