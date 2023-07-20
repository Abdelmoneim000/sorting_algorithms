#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order.
 * @array: the array to sort.
 * @size:the size of the array.
 *
 * Discription: this function uses the Selection sort algorithm.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;
	
	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			temp = array[min_idx];
			array[min_idx] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
