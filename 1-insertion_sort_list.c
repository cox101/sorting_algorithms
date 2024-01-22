#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion Sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *sorted = NULL;  /* Pointer to the sorted part of the list */
    listint_t *current = *list;
    listint_t *next_node;

    while (current != NULL)
    {
        next_node = current->next;

        if (sorted == NULL || sorted->n >= current->n)
        {
            /* Insert at the beginning of the sorted list or create a new sorted list */
            current->next = sorted;
            current->prev = NULL;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            listint_t *temp = sorted;

            /* Traverse the sorted list to find the right position for the current node */
            while (temp->next != NULL && temp->next->n < current->n)
                temp = temp->next;

            /* Insert the current node into the sorted list */
            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;
            current->prev = temp;
            temp->next = current;
        }

        /* Move to the next node in the original list */
        current = next_node;

        /* Print the current state of the doubly linked list after each insertion */
        print_list(*list);
    }

    /* Update the head of the list to point to the sorted part */
    *list = sorted;
}

