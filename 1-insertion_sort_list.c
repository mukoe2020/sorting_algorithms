#include "sort.h"

void swap_n(listint_t **head, listint_t *firstnode, listint_t *secondnode);
void insertion_sort_list(listint_t **list);

/**
* swap_n - a function that swaps two nodes in a linked list
* @head: pointer to the head of the linked list
* @firstnode: the first node to be swapped
* @secondnode: second node to be swapped
*/
void swap_n(listint_t **head, listint_t *firstnode, listint_t *secondnode)
{
	listint_t *prev, *next;

	prev = firstnode->prev;
	next = secondnode->next;

	/**
	* checks if firstnode is not empty and points to the second,
	* if in case it is empty the firstnode becomes the second node
	*/
	if (prev != NULL)
		prev->next = secondnode;
	else
		*head = secondnode;

	/* swapping nodes */
	firstnode->prev = secondnode;
	firstnode->next = next;
	secondnode->prev = prev;
	secondnode->next = firstnode;
	if (next)
		next->prev = firstnode;
}

/**
* insertion_sort_list - function that implements the insertion
* sort algorithm with a doubly linked list
* @list: the list to be sorted
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *front, *tempo;
/* checks if list is empty or has just one element*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	for (front = (*list)->next; front && front->prev; front = front->next)
	{
		for (; front && front->prev && front->n < front->prev->n;
		front = front->prev)
		{
			tempo = front->prev;
			swap_n(list, tempo, front);
			print_list(*list);
			front = front->next;
		}
	}
}
