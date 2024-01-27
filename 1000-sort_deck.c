#include "deck.h"

/**
 * sort_deck - Sorts a deck of cards in ascending order.
 * @deck: Pointer to the doubly linked list representing the deck.
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current;
    size_t length;
    deck_node_t *one, *two, *three, *four;

    length = deck_length(*deck);

    if (!deck || !*deck || length < 2)
        return;

    current = *deck;
    while (current)
    {
        if (current->prev && card_value(current) < card_value(current->prev))
        {
            one = current->prev->prev;
            two = current->prev;
            three = current;
            four = current->next;

            two->next = four;
            if (four)
                four->prev = two;
            three->next = two;
            three->prev = one;
            if (one)
                one->next = three;
            else
                *deck = three;
            two->prev = three;
            current = *deck;
            continue;
        }
        else
            current = current->next;
    }
}

/**
 * card_value - Returns the value of a card in the deck.
 * @node: Node representing a card in the deck.
 *
 * Return: Value of the card between 1 and 52.
 */
int card_value(deck_node_t *node)
{
    char *values[13] = {"Ace", "2", "3", "4", "5", "6",
                        "7", "8", "9", "10", "Jack", "Queen", "King"};
    char *suits[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
    int i, suit_value = 0;

    for (i = 1; i <= 13; i++)
    {
        if (!_strcmp(node->card->value, values[i - 1]))
            suit_value = i;
    }

    for (i = 1; i <= 4; i++)
    {
        if (!_strcmp(suits[node->card->kind], suits[i - 1]))
            suit_value = suit_value + (13 * i);
    }

    return suit_value;
}

/**
 * _strcmp - Compares two strings.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 *
 * Return: Less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2)
    {
        if (*s1 == '\0')
        {
            return 0;
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

/**
 * deck_length - Returns the length of the deck.
 * @deck: Head of the deck.
 *
 * Return: Length of the deck.
 */
size_t deck_length(deck_node_t *deck)
{
    size_t length = 0;

    while (deck)
    {
        length++;
        deck = deck->next;
    }
    return length;
}

