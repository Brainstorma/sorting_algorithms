#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 **/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 **/
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *x, y, z;

	x = array + right;
	for (y = z = left; z < right; z++)
	{
		if (array[z] < *x)
		{
			if (y < z)
			{
				swap_ints(array + z, array + y);
				print_array(array, size);
			}
			y++;
		}
	}

	if (array[y] > *x)
	{
		swap_ints(array + y, x);
		print_array(array, size);
	}

	return (y);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Description: Uses the Lomuto partition scheme.
 **/
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Lomuto partition scheme.
 **/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
