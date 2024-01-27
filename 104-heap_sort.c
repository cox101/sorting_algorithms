#include "sort.h"

/**
 * heap_sort - Sorts an array using the Heap Sort algorithm
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    /* Build a max heap */
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, (size_t)i, size);

    /* Extract elements from the heap one by one */
    for (int i = size - 1; i >= 0; i--)
    {
        /* Swap the root (maximum element) with the last element */
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;

        /* Print the array after each swap */
        if (i != 0)
            print_array(array, size);

        /* Heapify the remaining heap */
        heapify(array, (size_t)i, 0, size);
    }
}

/**
 * heapify - Turns an array into a heap tree
 * @array: Array to turn into a heap
 * @s: Size of the subtree
 * @root: Index of the subtree in the heap
 * @size: Size of the whole array
 */
void heapify(int *array, size_t s, size_t root, size_t size)
{
    size_t max, left, right;
    int tmp;

    max = root;
    left = (root * 2) + 1;
    right = (root * 2) + 2;

    /* Find the maximum among root, left child, and right child */
    if (left < s && array[left] > array[max])
        max = left;

    if (right < s && array[right] > array[max])
        max = right;

    /* If the maximum is not the root, swap and continue heapifying */
    if (max != root)
    {
        tmp = array[root];
        array[root] = array[max];
        array[max] = tmp;

        /* Print the array after each swap */
        print_array(array, size);

        /* Heapify the affected subtree */
        heapify(array, s, max, size);
    }
}

