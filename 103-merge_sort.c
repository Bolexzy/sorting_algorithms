#include "sort.h"

/**
* merge - merge function in merge_sort
* @l: size of left array
* @r: size of right array
* @m: wbue
* @array: array to merge in place
*/
void merge(int *array, int l, int m, int r)
{
	int i, j, k, n1, n2;
	int *left_arr, *right_arr;

	n1 = m - l + 1;
	n2 = r - m;
	left_arr = malloc((n1 + n2) * sizeof(int));
	for (i = 0; i < n1; i++)
		left_arr[i] = array[l + i];
	right_arr = (left_arr + n1);
	for (j = 0; j < n2; j++)
		right_arr[j] = array[m + j + 1];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (left_arr[i] <= right_arr[j])
		{
			array[k] = left_arr[i];
			k++;
			i++;
		}
		else
		{
			array[k] = right_arr[j];
			k++;
			j++;
		}
	}
	while (i < n1)
	{
		array[k++] = left_arr[i++];
	}
	while (i < n2)
	{
		array[k++] = right_arr[j++];
	}

	free(left_arr);
}

/**
* topdown_sort - dds
* @array: eafe
* @left: vrcs
* @right: sdfve
*/
void topdown_sort(int *array, int left, int right)
{
	int mid, n1;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		n1 = (mid - left) + 1;
		topdown_sort(array, left, mid);
		topdown_sort(array, mid + 1, right);

		printf("Merging...\n[left]: ");
		print_array(array, (mid - left) + 1);
		printf("[right]: ");
		print_array(array + n1, (right - mid));

		merge(array, left, mid, right);
		printf("[Done]: ");
		print_array(array,  n1 + (right - mid));
	}
}

/**
* merge_sort - svdv
* @array: cfswv
* @size: dfcveraf
*/
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	topdown_sort(array, 0, size - 1);
}
