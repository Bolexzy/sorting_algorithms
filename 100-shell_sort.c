#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order
*				using the shell sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Uses the Knuth interval sequence.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = 3 * gap + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			/* Put temp (the original array[i]) in its correct location */
			array[j] = temp;
		}
		print_array(array, size);
	}
}
