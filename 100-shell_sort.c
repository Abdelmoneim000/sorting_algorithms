#include "sort.h"

/**
 * swap - swaps two elements in ascending order.
 * @x: a pointer to an integer.
 * @y: a pointer to an integer.
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * shell_sort - sorts an array of integers in ascending order.
 * @array: the array to be sorted.
 * @size: the size of the given array.
 *
 * Description: This function uses Shell sort algorithm,
 *		that uses Knuth sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gab = 1;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	while (gab < size / 3)
		gab = gab * 3 + 1;
	while (gab >= 1)
	{
		for (j = gab; j < size; j++)
		{
			for (i = j; i >= gab; i -= gab)
			{
				if (array[i - gab] < array[i])
					break;
				swap(&array[i - gab], &array[i]);
			}
		}
		print_array(array, size);
		gab = gab / 3;
	}
}
