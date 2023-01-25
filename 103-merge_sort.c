#include "sort.h"

/**
* merge - Merges two subarrays of integers.
* @array: An array to split and sort.
* @buffer: A buffer to store the sublists.
* @l: The left index of the sub-array..
* @r: The right index of the sub-array.
* @m: The middle index of the sub-array.
*/
void merge(int *array, int *buffer, size_t l, size_t m, size_t r)
{
	size_t i, j, k = 0;

	i = l;
	j = m;
	while (i < m && j < r)
	{
		if (array[i] < array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}

	while (i < m)
	{
		buffer[k++] = array[i++];
	}
	while (j < r)
	{
		buffer[k++] = array[j++];
	}

	for (i = l, k = 0; i < r; i++)
		array[i] = buffer[k++];
}

/**
* topdown_sort - Implements the top-down merge sort algorithm.
* @array: An array of integers to divide and sort.
* @buffer: A buffer to store the sublists.
* @left: The left index of the sub-array.
* @right: The right index of the sub-array.
*/
void topdown_sort(int *array, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;

		topdown_sort(array, buffer, left, mid);
		topdown_sort(array, buffer, mid, right);

		printf("Merging...\n[left]: ");
		print_array(array + left, (mid - left));
		printf("[right]: ");
		print_array(array + mid, (right - mid));

		merge(array, buffer, left, mid, right);
		printf("[Done]: ");
		print_array(array + left,  (right - left));
	}
}

/**
* merge_sort - Sort an array of integers in ascending
*              order using the merge sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Implements the top-down merge sort algorithm.
*/
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	topdown_sort(array, buffer, 0, size);

	free(buffer);
}
