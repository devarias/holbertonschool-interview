#include "search_algos.h"

/**
 * advanced_binary - function description
 *
 * @array: array
 * @size: size
 * @value: value
 *
 * Return: an index
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i = 0, middle = 0, index = 0;
	int tmp;

	if (!array)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i == size - 1)
			printf("\n");
		else
			printf(", ");
	}

	middle = (size - 1) / 2;
	if (array[middle] == value)
	{
		if (size == 1 || array[middle - 1] < value)
			return (middle);
	}
	else if (size == 1)
	{
		return (-1);
	}
	if (array[middle] < value)
	{
		index += middle + 1, array += middle + 1;
		if (size % 2 != 0)
			middle--;
	}
	middle++;
	tmp = advanced_binary(array, middle, value);
	if (tmp != -1)
		return (tmp + index);
	return (-1);
}
