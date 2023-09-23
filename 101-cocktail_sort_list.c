#include "sort.h"

void cocktail_sort_list(listint_t **list);
void swap_ahead(listint_t **head, listint_t **currentnode,
listint_t **nextnode);
void swap_behind(listint_t **head, listint_t **currentnode,
listint_t **prevnode);

/**
* swap_ahead - function that swaps a node with the next node ahead of it
* @head: head of the linked list
* @currentnode: pointer to the current node
* @nextnode: pointer to the next node
*/
void swap_ahead(listint_t **head, listint_t **currentnode,
listint_t **nextnode)
{
	listint_t *temp = (*nextnode)->next;

	if ((*nextnode)->prev != NULL)
		(*nextnode)->prev->next = temp;
	else
		*head = temp;
	temp->prev = (*nextnode)->prev;
	(*nextnode)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *nextnode;
	else
	*currentnode = *nextnode;
	(*nextnode)->prev = temp;
	temp->next = *nextnode;
	*nextnode = temp;

}

/**
* swap_behind - function that swaps nodes with the node
* @head: double pointer to the head of doubly linked list
* @currentnode: the currentnode in the doubly linked list
* @prevnode: the previous node in the doubly linked list
*/
void swap_behind(listint_t **head, listint_t **currentnode,
listint_t **prevnode)
{
	listint_t *temp = (*prevnode)->prev;

	if ((*prevnode)->next != NULL)
		(*prevnode)->next->prev = temp;
	else
		*currentnode = temp;
	temp->next = (*prevnode)->next;
	(*prevnode)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *prevnode;
	else
		*head = *prevnode;
	(*prevnode)->next = temp;
	temp->prev = *prevnode;
	*prevnode = temp;
}

/**
* cocktail_sort_list - function that shows the cocktail shaker sort algorithm
*                      on a doubly linked list
* @list: the list to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *next_n;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	for (start = *list; start->next != NULL;)
	start = start->next;

	while (swapped == 0)
	{
		swapped = 1;
		for (next_n = *list; next_n != start; next_n = next_n->next)
		{
			if (next_n->n > next_n->next->n)
			{
				swap_ahead(list, &start, &next_n);
				print_list((const listint_t *)*list);
				swapped = 0;
			}
		}
		for (next_n = next_n->prev; next_n != *list; next_n = next_n->prev)
		{
			if (next_n->n < next_n->prev->n)
			{
				swap_behind(list, &start, &next_n);
				print_list((const listint_t *)*list);
				swapped = 0;
			}
		}
	}
}
