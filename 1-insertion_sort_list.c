#include "sort.h"

/**
 * len_list - returns the length of a linked list
 * @h: pointer to the list
 *
 * Return: length of list
 */
int len_list(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * insertion_sort_list - sorts a linked list with the Insertion Sort algorithm
 * @list: double pointer to the list to sort
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *current = NULL, *node_before = NULL;
	listint_t *node_to_insert = NULL, *node_after = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	current = *list;
	while (current)
	{
		if (current->prev && current->n < current->prev->n)
		{
			node_before = current->prev->prev;
			node_to_insert = current->prev;
			node_after = current->next;
			node_to_insert->next = node_after;
			if (node_after)
				node_after->prev = node_to_insert;
			current->next = node_to_insert;
			current->prev = node_before;
			if (node_before)
				node_before->next = current;
			else
				*list = current;
			node_to_insert->prev = current;
			current = *list;

			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
