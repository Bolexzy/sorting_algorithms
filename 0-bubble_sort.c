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
* bubble_sort - Sorts an array of integers in ascending order.
* @array: The integer array.
* @size: The size of the array.
*
* Description: Prints the 
*/
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    bool swapped;

    if (!array || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = false;

        for (j = 0;  j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array + j, array + j + 1);
                print_array(array, size);
                swapped = true;
            }
        }
            
        /* If no elements were swapped */
        if (swapped == false)
            break;
    }
}
