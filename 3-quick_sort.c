#include "sort.h"

/**
 * partition - partitions the array
 * @array: array to be partitioned
 * @lower: lower bound of array
 * @upper: upper bound of array
 * @size: size of the array
 *
 * Return: the value to quick_sort_helper
 */

int partition(int *array, int lower, int upper, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[upper];
	i = lower;

	for (j = lower; j < upper; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
			{
				print_array(array, size);
			}
			i++;
		}
	}
	temp = array[i];
	array[i] = array[upper];
	array[upper] = temp;
	if (i != upper)
	{
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_helper - helps the quick sort function
 * @array: array to be sorted
 * @lower: lower bound of array
 * @upper: upper bound of array
 * @size: size of array
 *
 * Return: Void
 */

void quick_sort_helper(int *array, int lower, int upper, size_t size)
{
	int location;

	if (lower < upper)
	{
		location = partition(array, lower, upper, size);
		quick_sort_helper(array, lower, location - 1, size);
		quick_sort_helper(array, location + 1, upper, size);
	}
}

/**
 * quick_sort - sorts an array using the quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
