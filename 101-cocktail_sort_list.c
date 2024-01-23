#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                      using the Cocktail Shaker sort algorithm.
 * @list: Double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &current, &current->next);
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, &current->prev, &current);
                swapped = 1;
                print_list(*list);
            }
        }
    } while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Double pointer to the head of the linked list.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
    listint_t *prev_node1, *next_node2;

    prev_node1 = (*node1)->prev;
    next_node2 = (*node2)->next;

    if (prev_node1 != NULL)
        prev_node1->next = *node2;
    else
        *list = *node2;

    (*node2)->prev = prev_node1;
    (*node2)->next = *node1;
    (*node1)->prev = *node2;
    (*node1)->next = next_node2;

    if (next_node2 != NULL)
        next_node2->prev = *node1;
}

