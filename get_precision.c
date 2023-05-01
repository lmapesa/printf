/**
 * get_precision - parse precision specifier from the format string
 * @format: Format string
 * @i: Pointer to the index in the format string
 * @ap: va_list contain the arguments
 *
 * Return: The precision specified in the format string, or -1 if not found
 */
int get_precision(const char *format, int *i, va_list ap)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return precision;

	precision = 0;
	curr_i++;

	if (format[curr_i] == '*')
	{
		precision = va_arg(ap, int);
		curr_i++;
	}
	else
	{
		while (isdigit(format[curr_i]))
		{
			precision = precision * 10 + (format[curr_i] - '0');
			curr_i++;
		}
	}

	*i = curr_i - 1;
	return precision;
}
