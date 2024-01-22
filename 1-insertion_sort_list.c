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
			one = current->previous->prev;
			two = current->previous;
			three = current;
			four = current->next;

			two->next = four;
			if (four)
				four->previous = two;
			three->next = two;
			three->previous = one;
			if (one)
				one->next = three;
			else
				*list = three;
			two->previous = three;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
