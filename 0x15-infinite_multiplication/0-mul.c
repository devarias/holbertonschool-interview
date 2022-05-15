#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * max - finds max between two ints
 * @a: first int
 * @b: second int
 * Return: bigger integer
 */
int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * print_error - prints an error message
 * @msg: error message
 * Return: Nothing
 */
void print_error(char *msg)
{
	while (*msg)
	{
		_putchar(*msg);
		msg++;
	}
}

/**
 * length - counts length of string
 * @str: string
 * Return: length of string
 */
int length(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * int_verification - checks if string is composed of digits
 * @str: string
 * Return: Nothing
 */
void int_verification(char *str)
{
	int i;

	for (i = 0; i < length(str); i++)
	{
		if (str[i] < '0' && str[i] > '9')
		{
			print_error("Error\n");
			exit(98);
		}
	}
}

/**
 * main - multiplies two numbers
 * @argc: arguments count
 * @argv: arguments array
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *str;
	int a_length, b_length, non_zero = 0;
	int i, j, k, x, *result;

	if (argc != 3)
	{
		print_error("Error\n");
		exit(98);
	}
	int_verification(argv[1]);
	int_verification(argv[2]);
	a_length = length(argv[1]);
	b_length = length(argv[2]);
	result = malloc(sizeof(int) * (a_length + b_length));
	for (i = a_length - 1; i >= 0; i--)
	{
		k = a_length - 1 - i;
		x = 0;
		for (j = b_length - 1; j >= 0; j--)
		{
			result[k] += (argv[1][i] - '0') * (argv[2][j] - '0') + x;
			x = result[k] / 10;
			result[k] = result[k] % 10;
			k++;
		}
		if (x)
			result[k++] = x;
		if (result[k - 1])
			non_zero = max(non_zero, k - 1);
	}
	str = malloc(sizeof(char) * 10000);
	for (i = non_zero; i >= 0; i--)
		str[non_zero - i] = result[i] + '0';
	str[non_zero + 1] = '\0';
	free(result);
	printf("%s\n", str);
	return (0);
}
