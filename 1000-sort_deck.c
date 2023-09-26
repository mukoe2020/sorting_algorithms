#include "deck.h"

/**
*swap - swaps 2 nodes in a doubly-linked list
*@m: address of first node
*@h: address of second node
*
*Return: void
*/
void swap(deck_node_t *m, deck_node_t *h)
{
	if (m->prev)
		m->prev->next = h;
	if (h->next)
		h->next->prev = m;
	m->next = h->next;
	h->prev = m->prev;
	m->prev = h;
	h->next = m;
}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (less_than(j->prev->card, j->card))
			{
				swap(j->prev, j);
				if (!j->prev)
					*list = j;
			}
			else
				j = j->prev;
		}

	}
}

/**
* sort_deck - sorts the deck by a given sort function
* @deck: address to pointer of head
*
*/
void sort_deck(deck_node_t **deck)
{
	insertion_sort_list(deck);
}

/**
* less_than - determines comparison order between two cards
* @a: pointer to first card
* @b: pointer to second card
*
* Return: true if a > b
*/
int less_than(const card_t *a, const card_t *b)
{
	char *s1, *s2, *values[] = {"King", "Queen", "Jack", "10", "9", "8",
		"7", "6", "5", "4", "3", "2", "Ace"};
	int val_a = 0, val_b = 0, i = 0;

	for (i = 0; i < 13; i++)
	{
		for (s1 = (char *)a->value, s2 = values[i]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_a = i;
			break;
		}
	}
	for (i = 0; i < 13; i++)
	{
		for (s1 = (char *)b->value, s2 = values[i]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_b = i;
			break;
		}
	}
	if (a->kind == b->kind)
		return (val_a < val_b);
	return (a->kind > b->kind);

}
