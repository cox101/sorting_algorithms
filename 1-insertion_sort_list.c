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
	 if (list == NULL || *list == NULL)
        return;

    listint_t *sorted = NULL;
    listint_t *current = *list;
    listint_t *next;

    while (current != NULL)
    {
        next = current->next;
        current->prev = current->next = NULL;

        if (sorted == NULL || sorted->n >= current->n)
        {
            current->next = sorted;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            listint_t *temp = sorted;

            while (temp->next != NULL && temp->next->n < current->n)
                temp = temp->next;

            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;

            temp->next = current;
            current->prev = temp;
        }

        print_list(sorted);

        current = next;
    }

    *list = sorted;
}
