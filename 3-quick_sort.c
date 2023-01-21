#include "sort.h"

/**
* swap - Swaps two integers in an array.
* @x: First integer.
* @y: Second integer.
*/
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
* lomuto_partition - Sorts elements in refernece to pivot
*					(lomuto partition scheme).
* @array: The array of integers.
* @low: The start index of the subset array to sort.
* @high: The last end index of the subset to sort.
* @size: The size of the array.
*
* Return: The final partition index(new pivot).
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, pi, j;

	pivot = *(array + high);

	pi = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			pi++;
			if (array[j] != array[pi])
			{
				swap(array + pi, array + j);
				print_array(array, size);
			}
		}
	}
	if (array[pi + 1] != array[high])
	{
		swap(array + pi + 1, array + high);
		print_array(array, size);
	}
	return (pi + 1);
}

/**
* lomuto_sort - Implement the quicksort algorithm through recursion.
* @array: An arrat of integers.
* @low: The start index of the partitioned array to sort.
* @high: The last end index of the partitioned array to sort.
* @size: The size of the array.
*
* Description: Uses the Lomuto partition scheme.
*/
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);

		lomuto_sort(array, low, partition_index - 1, size);
		lomuto_sort(array, partition_index + 1, high, size);
	}

}

/**
* quick_sort - Sort an array of integers in ascending
*              order using the quicksort algorithm.
* @array: An array of ints.
* @size: The size of the array.
*
* Description: Uses the Lomuto partition scheme. Prints
*              the array after each swap of two elements.
*/
void quick_sort(int *array, size_t size)
{
	int high, low;

	if (size <= 1 || array == NULL)
		return;

	low = 0;
	high = size - 1;

	lomuto_sort(array, low, high, size);
}
