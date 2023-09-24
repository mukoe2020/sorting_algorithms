#include "sort.h"

void swapping(int *m, int *h);
void bitonic_sort(int *array, size_t size);
void bitonic_sequence(int *array, size_t count, size_t index,
size_t sq, char flow);
void bitonic_merging(int *array, size_t count, size_t index,
size_t sq, char flow);

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
* bitonic_sequence - a function that converts an array of integers into
*                     bitonic sequences
* @array: the array to be sorted
* @count: the number of elements in the array
* @index: staring index of the bitonic sequence
* @sq: size of the bitonic sequence
* @flow: the direction of the bitonic sequence
*/
void bitonic_sequence(int *array, size_t count, size_t index,
size_t sq, char flow)
{
	size_t half = sq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, count, str);
		print_array(array + index, sq);

		bitonic_sequence(array, count, index, half, UP);
		bitonic_sequence(array, count, index + half, half, DOWN);
		bitonic_merging(array, count, index, sq, flow);

		printf("Result [%lu/%lu] (%s):\n", sq, count, str);
		print_array(array + index, sq);
	}
}


/**
* bitonic_merging - sorts a bitonic sequence into an array of integers
* @array: the array to be sorted
* @count: the number of elements in the array
* @index: staring index of the bitonic sequence
* @sq: size of the bitonic sequence
* @flow: the direction of the bitonic sequence
*/
void bitonic_merging(int *array, size_t count, size_t index,
size_t sq, char flow)
{
	size_t h, midpoint = sq / 2;

	if (sq > 1)
	{
		for (h = index; h < index + midpoint; h++)
		{
			if ((flow == UP && array[h] > array[h + midpoint]) ||
			(flow == DOWN && array[h] < array[h + midpoint]))
			swapping(array + h, array + h + midpoint);
		}
		bitonic_merging(array, count, index, midpoint, flow);
		bitonic_merging(array, count, index + midpoint, midpoint, flow);
	}
}

/**
* bitonic_sort - function used to sort an array of integers, with the
*                bitonic sort algorithm
* @array: the array to be sorted
* @size: the size of the array
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, UP);

}
