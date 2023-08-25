#include "main.h"

/**
 * print_string_err - writes string to stderr
 * @str: The string to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_string_err(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		count += _putchar_err(str[i++]);
	}
	return (count);
}
