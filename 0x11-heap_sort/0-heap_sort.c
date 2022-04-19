#include "sort.h"

/**
 * heap_sort - Sort an array
 *
 * @array: The array
 * @size: Number of elements
 *
 * Return: None
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		down(array, i, 0, size);
	}
}

/**
 * down - shift down method
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @i: Initialize largest as root
 * @size_array: Number of elements in @array real
 *
 * Return: Nothing
 */
void down(int *array, int size, int i, int size_array)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < size && array[l] > array[largest])
		largest = l;

	if (r < size && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size_array);
		down(array, size, largest, size_array);
	}
}

/**
 * check - check
 *
 * @array: The array
 * @size: Number of elements
 *
 * Return: 1-0
 */
int check(int *array, int size)
{
	int i;

	for (i = 0; i < size - 1; i++)
		if (array[i] > array[i + 1])
			return (0);
	return (1);
}

/**
 * swap - Swap
 * @a: Argument a
 * @b: Argument b
 *
 * Return: None
 */
void swap(int *a, int *b)
{
	int c;

	c = *b;
	*b = *a;
	*a = c;
}
