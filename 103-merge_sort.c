#include "sort.h"

void merge_sub_set(int *subset, int *sorted_set, size_t left,

size_t mid, size_t right);
void merge_recursion(int *subset, int *set_size, size_t left, size_t right);

void merge_sort(int *array, size_t size);

/**
* merge_sub_set - Function that sorts sub sets of an array of integers
* @subset: a sub set or a subarray of integers
* @sorted_set: will contain the sorted subarray of integers
* @left: the left side index of the sub array
* @mid: the middle side of the sub array
* @right: the right side of the sub array
*/
void merge_sub_set(int *subset, int *sorted_set, size_t left,
size_t mid, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subset + left, mid - left);

	printf("[right]: ");
	print_array(subset + mid, right - mid);

	for (i = left, j = mid; i < mid && j < right; k++)
		sorted_set[k] = (subset[i] < subset[j]) ? subset[i++] : subset[j++];
	for (; i < mid; i++)
		sorted_set[k++] = subset[i];
	for (; j < right; j++)
		sorted_set[k++] = subset[j];
	for (i = left, k = 0; i < right; i++)
		subset[i] = sorted_set[k++];

	printf("[Done]: ");
	print_array(subset + left, right - left);

}

/**
* merge_recursion - function that implements the merge sort algorithm
*                   with recursion
* @subset: sorted_setay of integers
* @sorted_set: contains the sorted subarray
* @left: left side of the subarray
* @right: right side of the subarray
*/
void merge_recursion(int *subset, int *sorted_set, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_recursion(subset, sorted_set, left, mid);
		merge_recursion(subset, sorted_set, mid, right);
		merge_sub_set(subset, sorted_set, left, mid, right);
	}
}

/**
* merge_sort - sort an array of integers using the merge sort algorithm
* @array: array to be sorted
* @size: size of the array to be sorted
*/
void merge_sort(int *array, size_t size)
{
	int *sorted_set;

	if (array == NULL || size < 2)
		return;

	sorted_set = malloc(sizeof(int) * size);
	if (sorted_set == NULL)
		return;

	merge_recursion(array, sorted_set, 0, size);

	free(sorted_set);
}
