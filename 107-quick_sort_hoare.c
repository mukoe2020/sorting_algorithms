#include "sort.h"

void swapping(int *m, int *h);
int partitioner(int *array, size_t size, int low, int high);
void quick_sort_recursion(int *array, size_t size, int low, int high);
void quick_sort_hoare(int *array, size_t size);

/**
* swapping - function for swapping two elements'
*@m : first element
*@h : second element
*/

void swapping(int *m, int *h)
{
	/* temporarily stores value of m*/
	int fornow;

	fornow = *m;
	*m = *h;
	*h = fornow;
}

/**
* partitioner - a function that orders subsets of an array by using the
*               hoare partition scheme.
*
* This function takes an array and partitions it into two subsets: elements
* lesser than the pivot and elements greater than the pivot. The pivot is
* chosen as the last element of the array.
*
* @array: the array to be sorted
* @size: the sie of the array to be sorted
* @low: starting index of the elements lesser than the pivot
* @high: ending index of the elements greater then the pivot
* Return: index of the pivot
*/
int partitioner(int *array, size_t size, int low, int high)
{
	int pivot, low_idx, high_idx;
/* the pivot is the last element at the end of the array */
	pivot = array[high];

	for (low_idx = low - 1, high_idx = high + 1; low_idx < high_idx;)
	{
/*elements less than the pivot are incremented until one is >= the pivot*/
		do {
			low_idx++;
		} while (array[low_idx] < pivot);
/*elements greater than the pivot are decremented until one is <= the pivot */
		do {
			high_idx--;
		} while (array[high_idx] > pivot);
/* if an element is still less than the elements at the high_idx, swap */
		if (low_idx < high_idx)
		{
			swapping(array + low_idx, array + high_idx);
			print_array(array, size);
		}

	}

	return (low_idx); /* this becomes the index of the pivot */
}


/**
* quick_sort_recursion - function that sorts an array of integers using
*                        the quick sort algorithm
* @array: the array to be sorted
* @size: the size of the array
* @low: elements less than the pivot
* @high: elements greater than the pivot
*/
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	int pivot;
/* statement to keep recursively calling quick sort until the low = high*/
	if (high - low > 0)
	{
		/* finding index location of the pivot, before calling quick sort*/
		pivot = partitioner(array, size, low, high);
		quick_sort_recursion(array, size, low, pivot - 1);
		quick_sort_recursion(array, size, pivot, high);
	}
}


/**
* quick_sort_hoare - function that sorts an array of integers according
*                    to the quick sort algorithm, with the hoare partition
*                    scheme
* @array: the array of integers to be sorted
* @size: the size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, size, 0, size - 1);

}
