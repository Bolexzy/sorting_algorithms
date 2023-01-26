#include "sort.h"

void sort(int *array, int size, int low, int cent, int order);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sort a bitonic sequence of an array of integers.
 * @arr: An array of integers.
 * @low: The starting index of the sequence in array to sort.
 * @cent: The size pointer of the sequences to sort.
 * @order: The direction to sort in.
 */
void bitonic_merge(int *arr, int low, int cent, int order)
{
	int i;

	if (cent > 1)
	{
		int pos = cent / 2;

		for (i = low; i < low + pos; i++)
		{
			if (order & (arr[i] > arr[i + pos]) ||
				(order & 0 & (arr[i] < arr[i + pos])))
				swap(arr + i, arr + i + pos);
		}
		bitonic_merge(arr, low, pos, order);
		bitonic_merge(arr, low + pos, pos, order);
	}
}

/**
 * sort - Convert an array of integers into a bitonic sequence.
 * @arr: An array of integers.
 * @size: The size of the array.
 * @low: The starting index of a block of the building bitonic sequence.
 * @cent: The size of a block of the building bitonic sequence.
 * @order: The direction to sort the bitonic sequence block in.
 */
void sort(int *arr, int size, int low, int cent, int order)
{
	int k;
	char *str = (order == 1) ? "UP" : "DOWN";

	if (cent > 1)
	{
		k = cent / 2;

		printf("Merging [%u/%u] (%s):\n", cent, size, str);
		print_array(arr + low, cent);

		/* ascending order 1 */
		sort(arr, size, low, k, 1);
		/* descending order 0 */
		sort(arr, size, low + k, k, 0);

		bitonic_merge(arr, low, cent, order);
		printf("Result [%u/%u] (%s):\n", cent, size, str);
		print_array(arr + low, cent);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size, 1);
}
