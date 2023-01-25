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
* heapify - Create a max heap binary tree using sift down algorithm.
* @array: An array of integers represented as binary tree.
* @size: The size of the array.
* @base: The heap base for the binary tree.
* @root: The root node of the binary tree.
*/
void heapify(int *array, int size, int base, int root)
{
	int largest = root, left_child, right_child;

	left_child = 2 * root + 1;
	right_child = 2 * root + 2;

	if (left_child < base && array[left_child] > array[largest])
		largest = left_child;
	if (right_child < base && array[right_child] > array[largest])
		largest = right_child;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		heapify(array, size, base, largest);
	}
}

/**
* heap_sort -  Sort an array of integers in ascending
*             order using the heap sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Implements the sift-down heap sort
* algorithm. Prints the array after each swap.
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		/* implement max heap sift down */
		heapify(array, size, size, i);
	}

	for (i = (size - 1); i >= 0; i--)
	{
		/* move current root(max) to end */
		swap(&array[0], &array[i]);
		print_array(array, size);
		/* call max heapify on reduced heap (base = i--) */
		heapify(array, size, i, 0);
	}
}

