#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _puts - Prints a string
 *
 * @s: string to print
 */

void _puts(char *s)
{
	while (*s)
		_putchar(*s++);
	_putchar('\n');
}

/**
 * exit98 - Exits with status code 98
 */

void exit98(void)
{
	_puts("Error");
	exit(98);
}

/**
 * _atoi - converts a number in a string to an int
 *
 * @s: string containing the number to convert
 *
 * Return: an int
 */

long _atoi(char *s)
{
	int i = 0, sign = 0;
	long res = 0;

	while (s[i] && (!(s[i] >= '0') || !(s[i] <= '9')))
	{
		if (s[i] == '-')
			sign++;
		i++;
	}
	sign = (sign % 2) ? -1 : 1;
	while (s[i] && ((s[i] >= '0') && (s[i] <= '9')))
		res = res * 10 + (s[i++] - '0') * sign;
	return (res);
}

/**
 * _isnumber - Checks if a string is a number
 *
 * @s: a string
 *
 * Return: length if number is valid, exit if not
 */

int _isnumber(char *s)
{
	int i = 0;

	if (!s)
		exit98();

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			exit98();
	}

	return (i);
}

/**
 * _strlen  - Returns the length of a string s
 *
 * @s: pointer to a string
 *
 * Return: the length of string s
 */

int _strlen(char *s)
{
	int len = 0;

	if (s)
	{
		while (s[len])
			len++;
		return (len);
	}

	return (0);
}

/**
 * main - Entry point. Multiplies 2 nums and prints the result
 *
 * I lost plenty enough braincells trying to do it the first time
 * during the foundations. All you'll get is this lousy attempt, because
 * a) I'll never have to do anything like this ever again,
 * b) I never actually WANT to do this ever again, and
 * c) because if I am ever asked to do this again, I might actually
 * consider exiling myself to a remote desert island.
 *
 * @argc: number of arguments
 * @argv: value of arguments
 *
 * Return: 0 if success.
 */

int main(int argc, char **argv)
{
	char *num1 = argv[1], *num2 = argv[2];

	if (argc != 3 || !_isnumber(num1) || !_isnumber(num2))
		exit98();

	if (_strlen(num1) < 10 && _strlen(num2) < 10)
	{
		printf("%ld\n", _atoi(num1) * _atoi(num2));
		return (0);
	}

	return (0);
}
