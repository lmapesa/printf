#include "holberton.h"

/**
 * print_reversed - Call a fn to reverse and print a string
 * @arg: Arg passed to the function
 * Return: amount of printed chars
 */
int print_reversed(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		_write_char(ptr[len]);
	free(ptr);
	return (len);
}

/**
 * rot13 - Convert string to rot13
 * @list: string to convert
 * Return: converted string
 */
int rot13(va_list list)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_write_char(u[x]);
				break;
			}
		}
		if (x == 53)
			_write_char(str[i]);
	}
	return (i);
}
