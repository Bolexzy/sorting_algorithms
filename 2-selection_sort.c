#include "sort.h"

/**
* selection_sort - Sorts an array of ints in ascending order using
*					the selection sort algorithm.
* @array: The array of ints.
* @size: The size of the array.
*
* Description: Prints the array after each swap.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx, temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		/* swap if new minimum element found */
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
