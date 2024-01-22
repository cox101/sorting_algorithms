#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in asc order using
 *                        the Insertion Sort algorithm.
 * @list: Double pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{

	if (list == NULL || *list == NULL || (*list)->next == NULL)

		return;

	listint_t *sorted = NULL;
	listint_t *unsorted = *list;
	listint_t *next;

	while (unsorted != NULL)
	{
		next = unsorted->next;

		if (sorted == NULL || sorted->n >= unsorted->n)
		{
			unsorted->next = sorted;
			unsorted->prev = NULL;
			if (sorted != NULL)
				sorted->prev = unsorted;
			sorted = unsorted;
		}

		else
		{

			listint_t *current = sorted;

			while (current->next != NULL && current->next->n < unsorted->n)
				current = current->next;
			unsorted->next = current->next;
			unsorted->prev = current;
			if (current->next != NULL)
				current->next->prev = unsorted;
			current->next = unsorted;
		}

		unsorted = next;
		print_list(sorted);
	}
	*list = sorted;
}
