#include "holberton.h"

/**
 * _write_char - write the char c to stdout
 * @c: The char 2 print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _write_char(char c)
{
	return (write(1, &c, 1));
}
