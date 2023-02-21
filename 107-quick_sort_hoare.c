#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Order a subset of an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 **/
int hoare_partition(int *array, size_t size, int left, int right)
{
	int x, y, z;

	x = array[right];
	for (y = left - 1, z = right + 1; y < z;)
	{
		do {
			y++;
		} while (array[y] < x);
		do {
			z--;
		} while (array[z] > x);

		if (y < z)
		{
			swap_ints(array + y, array + z);
			print_array(array, size);
		}
	}

	return (y);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Description: Uses the Hoare partition scheme.
 **/
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 **/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
