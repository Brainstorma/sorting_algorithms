#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 **/
int get_max(int *array, int size)
{
	int max, nmax;

	for (max = array[0], nmax = 1; nmax < size; nmax++)
	{
		if (array[nmax] > max)
			max = array[nmax];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints the counting array after setting it up.
 **/
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, nmax;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (nmax = 0; nmax < (max + 1); nmax++)
		count[nmax] = 0;
	for (nmax = 0; nmax < (int)size; nmax++)
		count[array[nmax]] += 1;
	for (nmax = 0; nmax < (max + 1); nmax++)
		count[nmax] += count[nmax - 1];
	print_array(count, max + 1);

	for (nmax = 0; nmax < (int)size; nmax++)
	{
		sorted[count[array[nmax]] - 1] = array[nmax];
		count[array[nmax]] -= 1;
	}

	for (nmax = 0; nmax < (int)size; nmax++)
		array[nmax] = sorted[nmax];

	free(sorted);
	free(count);
}
