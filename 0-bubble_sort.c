#include "sort.h"

/**
 * swap - swaps two elements in ascending order.
 * @x: a pointer to an integer.
 * @y: a pointer to an integer.
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}
/**
 * bubble_sort - sorts an array of integersi in ascending order.
 * @array: a pointer to an array of integers.
 * @size: the size of the array.
 *
 * Description: This function uses Bubble sort algorithm.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	
	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
