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
 * lomuto_partition - Lomuto partition.
 * @array: The array to be sorted.
 * @size: the size of the array.
 * @low: starting index.
 * @high: the ending index.
 * Return: the index of the new pivot.
 *
 * Description: The Lomuto partition scheme is
 *		a partitioning scheme used in the QuickSort
 *		algorithm to divide an array into two sub-arrays.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int j, i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > pivot)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sort_recursion - Aplys a recursive quick sorting.
 * @array: the array to be sorted.
 * @size: size of the array.
 * @low: the starting index.
 * @high: the ending index.
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, size, low, high);
		quick_sort_recursion(array, size, low, pivot - 1);
		quick_sort_recursion(array, size, pivot + 1, high);
	}
}
/**
 * quick_sort - sorts a an array of integers in ascending order.
 * @array: the array to sort.
 * @size: the size of the array.
 *
 * Description: This function uses the Quik sort algorithm.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}
