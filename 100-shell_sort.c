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
* shell_sort - function that implements the shell sort algorithm
* @array: the array to be sorted
* @size: the size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t m, h, interval;

/* if array is empty or has only one element, exit*/
	if (array == NULL || size < 2)
	return;

/* calculating the interval based on the Knuth sequence*/
	interval = 1;
	while (interval < size / 3)
	interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (m = interval; m < size; m++)
		{
			h = m;
			while (h >= interval && array[h - interval] > array[h])
			{
				swapping(array + h, array + (h - interval));
				h -= interval;
			}
		}
		print_array(array, size);
	}


}
