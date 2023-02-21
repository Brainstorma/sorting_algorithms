#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

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
 * radix_counting_sort - Sort the significant digits.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 **/
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t nmax;

	for (nmax = 0; nmax < size; nmax++)
		count[(array[nmax] / sig) % 10] += 1;

	for (nmax = 0; nmax < 10; nmax++)
		count[nmax] += count[nmax - 1];

	for (nmax = size - 1; (int)nmax >= 0; nmax--)
	{
		buff[count[(array[nmax] / sig) % 10] - 1] = array[nmax];
		count[(array[nmax] / sig) % 10] -= 1;
	}

	for (nmax = 0; nmax < size; nmax++)
		array[nmax] = buff[nmax];
}

/**
 * radix_sort - Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 **/
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
