#include "sort.h"

void swap_n(listint_t **head, *firstnode, *secondnode);
void insertion_sort_list(listint_t **list);

/**
* swap_n - a function that swaps two nodes in a linked list
* @head: pointer to the head of the linked list
* @firstnode: the first node to be swapped
* @secondnode: second node to be swapped
*/
void swap_n(listint_t **head, *firstnode, *secondnode)
{
	listint *previous, *next;

	previous = firstnode->previous
	next = secondnode->next;

	/**
	* checks if firstnode is not empty and points to the second,
	* if in case it is empty the firstnode becomes the second node
	*/
	if (previous != NULL)
		previous->next = secondnode;
	else
		*head = secondnode;

	/* swapping nodes */
	firstnode->previous = secondnode;
	firstnode->next = next;
	secondnode->prev = previous;
	secondnode->next = firstnode
	if (next)
		next->previous = firstnode;
}
