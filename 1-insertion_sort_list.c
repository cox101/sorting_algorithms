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
 * insertion_sort_list - sorts a linked list with the Insert Sort algorithm
 * @list: double pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
    if (!list || !(*list) || len_list(*list) < 2)
        return;

    listint_t *current = *list;

    while (current)
    {
        if (current->prev && current->n < current->prev->n)
        {
            listint_t *prev_prev = current->prev->prev;
            listint_t *prev = current->prev;
            listint_t *current_node = current;
            listint_t *next_node = current->next;

            prev->next = next_node;
            if (next_node)
                next_node->prev = prev;
            current_node->next = prev;
            current_node->prev = prev_prev;
            if (prev_prev)
                prev_prev->next = current_node;
            else
                *list = current_node;
            prev->prev = current_node;
            current = *list;
            print_list(*list);
        }
        else
        {
            current = current->next;
        }
    }
}

