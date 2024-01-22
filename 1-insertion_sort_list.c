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
 * insertion_sort_list - Sorts a doubly linked list of int in ascending order
 *                       using the Insertion Sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *One = NULL;
	listint_t *Two = NULL, *Three = NULL, *Four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	current = *list;

	while (current)
	{
		if (current->previous && current->n < current->previous->n)
		{
			One = current->previous->previous;
			Two = current->previous;
			Three = current;
			Four = current->next;

			Two->next = Four;
			if (Four)
				Four->previous = Two;
			Three->next = Two;
			Three->previous = One;
			if (One)
				One->next = Three;
			else
				*list = Three;
			Two->previous = Three;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
