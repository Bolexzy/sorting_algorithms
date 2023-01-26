#include "sort.h"

/**
* get_max - Get the maximum value in an array of integers.
* @arr: An array of integers.
* @size: The size of the array.
*
* Return: The maximum integer in the array.
*/
int get_max(int *arr, size_t size)
{
	size_t i;
	int max = arr[0];

	for (i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

/**
* count_sort - Sorts an array of integers using the significant digits
*                       in ascending order using the counting sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
* @exp: The exponential to get the significant digits to sort on.
* @buff: A buffer to store the sorted array.
*/
void count_sort(int *array, int size, int exp, int *buff)
{
	int count[10] = {0}, i;

	/* store count of occurences of array i in count */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i <= 9; i++)
		count[i] += count[i - 1];

	/* Build the sorted array from count index of array i*/
	for (i = size - 1; i >= 0; i--)
	{
		buff[--count[(array[i] / exp) % 10]] = array[i];
	}

	/* copy sorted array back into the array */
	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
* radix_sort - Sort an array of integers in ascending
*              order using the radix sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Implements the LSD radix sort algorithm. Prints
* the array after each significant digit increase.
*/
void radix_sort(int *array, size_t size)
{
	int exp_div, max;
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	max = get_max(array, size);

	for (exp_div = 1; max / exp_div > 0; exp_div *= 10)
	{
		count_sort(array, size, exp_div, buffer);
		print_array(array, size);
	}

	free(buffer);
}
