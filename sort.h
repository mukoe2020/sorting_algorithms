#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* macros for bitonic sort algorithm*/
#define UP 0
#define DOWN 1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printing  functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algoritms */
void bubble_sort(int *array, size_t size);
void swapping(int *m, int *h);
void insertion_sort_list(listint_t **list);
void swap_n(listint_t **head, listint_t *firstnode, listint_t *secondnode);
void selection_sort(int *array, size_t size);


void shell_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_ahead(listint_t **head, listint_t **currentnode,
listint_t **nextnode);
void swap_behind(listint_t **head, listint_t **currentnode,
		listint_t **prevnode);


void merge_sort(int *array, size_t size);
void merge_sub_set(int *subset, int *sorted_set, size_t left,
size_t mid, size_t right);
void merge_recursion(int *sub_set, int *sorted_set, size_t left, size_t right);
void radix_sort(int *array, size_t size);
int maximum_int(int *array, int size);
void radix_algorithm(int *array, size_t size, int sg, int *sorted_set);


void bitonic_sort(int *array, size_t size);
void bitonic_sequence(int *array, size_t count, size_t index,
size_t sq, char flow);
void bitonic_merging(int *array, size_t count, size_t index,
size_t sq, char flow);

void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int partitioner(int *array, size_t size, int low, int high);
void quick_sort_recursion(int *array, size_t size, int low, int high);


#endif /* SORT_H */
