#include "sort.h"

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
* bubble_sort - function implementing bubble-sort-algo
* @array: the array to be sorted
* @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, h, len = size;
	int swapped = 0;

	if (array == NULL || len < 2)
	return;

	for (i = 0; i < len - 1; i++)
	{
		swapped = 0;
		for (h = 0; h < len - i - 1; h++)
		{
			if (array[h] > array[h + 1])
			{
				swapping(&array[h], &array[h + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
