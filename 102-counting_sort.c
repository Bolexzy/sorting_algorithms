#include "sort.h"

/**
* max_integer - Get the maximum value in an array of integers.
* @arr: An array of integers.
* @size: The size of the array.
*
* Return: The maximum integer in the array.
*/
int max_integer(int *arr, size_t size)
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
* counting_sort - Sort an array of integers in ascending order
*                 using the counting sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Prints the counting array after setting it up.
*/
void counting_sort(int *array, size_t size)
{
	int *output, *count, i, k;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	k = max_integer(array, size);

	count = malloc(sizeof(int) * k);
	if (count == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i <= k; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);

	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
