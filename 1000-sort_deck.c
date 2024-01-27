#include "deck.h"

/**
 * sort_deck - sorts a deck of cards in ascending order.
 * @deck: doubly linked list of cards to sort.
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *curr;
    size_t len;
    deck_node_t *one, *two, *three, *four;

    /* Get the length of the deck */
    len = list_len_deck(*deck);

    /* Check if the deck is empty or already sorted */
    if (!deck || !*deck || len < 2)
        return;

    curr = *deck;

    /* Iterate through the deck to perform sorting */
    while (curr)
    {
        /* If the current card is smaller than the previous one, swap them */
        if (curr->prev && card_value(curr) < card_value(curr->prev))
        {
            /* Store pointers to nodes for easy swapping */
            one = curr->prev->prev;
            two = curr->prev;
            three = curr;
            four = curr->next;

            /* Update next and previous pointers to perform the swap */
            two->next = four;
            if (four)
                four->prev = two;
            three->next = two;
            three->prev = one;
            if (one)
                one->next = three;
            else
                *deck = three; /* Update head if necessary */
            two->prev = three;

            /* Reset current to the beginning of the deck for the next iteration */
            curr = *deck;
            continue;
        }
        else
            curr = curr->next; /* Move to the next card */
    }
}

/**
 * card_value - returns the value of a card.
 * @node: card in the deck.
 * Return: value between 1 and 52.
 */
int card_value(deck_node_t *node)
{
    /* Arrays representing card values and kinds */
    char *val[13] = {"Ace", "2", "3", "4", "5", "6",
                     "7", "8", "9", "10", "Jack", "Queen", "King"};
    char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};

    int i, kind_val = 0;

    /* Check the value of the card and calculate its unique value*/
    for (i = 1; i <= 13; i++)
    {
        if (!_strcmp(node->card->value, val[i - 1]))
            kind_val = i;
    }

    /* Check the kind of the card and adjust the value accordingly*/
    for (i = 1; i <= 4; i++)
    {
        if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
            kind_val = kind_val + (13 * i);
    }

    return kind_val;
}

/**
 * _strcmp - compares two strings.
 * @s1: first string to compare.
 * @s2: second string to compare.
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
    /* Compare characters until a difference is found*/
    while (*s1 == *s2)
    {
        if (*s1 == '\0')
        {
            return 0; 
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2); /*Return the difference*/
}

/**
 * list_len_deck - function returns the length of the list.
 * @list: head of the list.
 * Return: length of the list.
 */
size_t list_len_deck(deck_node_t *list)
{
    size_t len = 0;

    /* Traverse the list to count the number of nodes*/
    while (list)
    {
        len++;
        list = list->next;
    }
    return len;
}

