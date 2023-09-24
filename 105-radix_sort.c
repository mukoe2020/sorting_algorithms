#include "sort.h"

void radix_sort(int *array, size_t size);
int maximimum_int(int *array, int size);
void radix_algorithm(int *array, size_t size, int sg, int *sorted_set);

/**
 * maximum_int - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int maximum_int(int *array, int size)
{
	int maxim, i;

	for (maxim = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxim)
			maxim = array[i];
	}

	return (maxim);
}

/**
 * radix_algorithm - Sort the significant digits of an array of integers
 *                    using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sg: The significant digit
 * @sorted_set: A set to store the sorted array.
 */
void radix_algorithm(int *array, size_t size, int sg, int *sorted_set)
{
	int numbers[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		numbers[(array[i] / sg) % 10] += 1;

	for (i = 1; i < 10; i++)
		numbers[i] += numbers[i - 1];


	for (i = size - 1; (int)i >= 0; i--)
	{
		sorted_set[numbers[(array[i] / sg) % 10] - 1] = array[i];
		numbers[(array[i] / sg) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_set[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int maxim, sg, *sorted_set;

	if (array == NULL || size < 2)
		return;

	sorted_set = malloc(sizeof(int) * size);
	if (sorted_set == NULL)
		return;

	maxim = maximum_int(array, size);
	for (sg = 1; maxim / sg > 0; sg *= 10)
	{
		radix_algorithm(array, size, sg, sorted_set);
		print_array(array, size);
	}

	free(sorted_set);
}
