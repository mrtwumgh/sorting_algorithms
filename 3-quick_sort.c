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
	int pivot, start, end, temp;

	pivot = array[lower];
	start = lower;
	end = upper;

	while (start < end)
	{
		if (array[start] <= pivot)
		{
			start++;
		}
		if (array[end] > pivot)
		{
			end--;
		}
		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			print_array(array, size);
		}
	}
	temp = array[lower];
	array[lower] = array[end];
	array[end] = temp;
	print_array(array, size);

	return (end);
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
