#include "main.h"

/**
 * print_string - writes string to stdout
 * @str: The string to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_string(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		count += _putchar(str[i++]);
	}
	return (count);
}
