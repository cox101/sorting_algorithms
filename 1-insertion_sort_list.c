#include "sort.h"

/**
 * len_list -return the length of the linked list
 * @h: pointer to list
 * Return: length of the list
 */

int len_list(listint_t *h)
{
	int length = 0;

	while (h)
	{
		length++;
		h = h->next;
	}
	return (length);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion Sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list);
{
	if (!list || !(*list) || len_list(*list) < 2)
        return;

    listint_t *curr, *prev, *next;

    for (curr = (*list)->next; curr; curr = next)
    {
        next = curr->next;

        while (curr->prev && curr->n < curr->prev->n)
        {
            prev = curr->prev;
            prev->next = curr->next;

            if (curr->next)
                curr->next->prev = prev;

            curr->next = prev;
            curr->prev = prev->prev;
            prev->prev = curr;

            if (curr->prev)
                curr->prev->next = curr;
            else
                *list = curr;

            print_list(*list);
        }
    }
}
