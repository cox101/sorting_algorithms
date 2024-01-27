#include "sort.h"

/**
 * heapify - Convert the array into a max heap
 * @array: Array to be heapified
 * @size: Size of the array
 * @i: Index of the root of the current subtree
 * @total_size: Total size of the array
 */
void heapify(int *array, size_t size, size_t i, size_t total_size)
{
    size_t largest = i;
    size_t left_child = 2 * i + 1;
    size_t right_child = 2 * i + 2;

    if (left_child < size && array[left_child] > array[largest])
        largest = left_child;

    if (right_child < size && array[right_child] > array[largest])
        largest = right_child;

    if (largest != i)
    {
        /* Swap array[i] and array[largest] */
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        print_array(array, total_size);

        heapify(array, size, largest, total_size);
    }
}

/**
 * heap_sort - Sorts an array using the Heap Sort algorithm
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Build a max heap */
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);

    /* Extract elements from the heap one by one */
    for (int i = size - 1; i > 0; i--)
    {
        /* Swap the root (maximum element) with the last element */
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        print_array(array, size);

        /* Reduce the heap size and heapify the root element */
        heapify(array, i, 0, size);
    }
}

