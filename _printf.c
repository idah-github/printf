#include "main.h"
int print(const char *fmt, int *ind, va_list ap, char buffer[],
		int flags, int width, int precision, int size);
void print_buffer(char buffer[], int *buff_ind);

/**
* _printf -  function printf
* @format: format.
* Return: the chars.
*/
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = gflags(format, &i);
			width = gwidth(format, &i, list);
			precision = gprecision(format, &i, list);
			size = gsize(format, &i);
			++i;
			printed = print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
* print_buffer - Print buffer content if it exist
* @buffer: Array of chars
* @buff_ind: Index to add next char, length.
*/
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
